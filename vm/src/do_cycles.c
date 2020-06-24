/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cycles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <alagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 12:35:30 by agardina          #+#    #+#             */
/*   Updated: 2020/06/15 12:55:17 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

static void	do_check(t_data *data)
{
	t_carriage *current;

	data->vm.nb_checks++;
	current = data->carriages;
	while (current)
	{
		if (data->vm.cycle_to_die <= data->vm.nb_cycles - current->last_live)
			current = delete_one_carriage(data, current);
		else
			current = current->next;
	}
	if (data->vm.cycle_to_die <= 0)
		delete_all_carriages(data);
	if (NBR_LIVE <= data->vm.nb_live || MAX_CHECKS <= data->vm.nb_checks)
	{
		data->vm.cycle_to_die -= CYCLE_DELTA;
		if (data->vm.verbose & 0b010)
			ft_printf("Cycle to die is now %d\n", data->vm.cycle_to_die);
		data->vm.nb_checks = 0;
	}
	data->vm.nb_live = 0;
	data->vm.cycles_since_last_check = 0;
}

static void	set_ope_code(t_data *data, t_carriage *current)
{
	static const int	waiting_time[16] = {10, 5, 5, 10, 10, 6, 6, 6, 20,
	25, 25, 800, 10, 50, 1000, 2};
	int32_t				opcode;

	opcode = get_from_ram(data, current->pos, 1);
	if (0x01 <= opcode && opcode <= 0x10)
	{
		current->opcode = opcode;
		current->cycles_to_wait = waiting_time[opcode - 1] - 1;
	}
	else
	{
		current->bytes_to_jump = 0;
		current->cycles_to_wait = -1;
		current->pos = get_pos(current->pos + 1);
	}
}

static void	do_current_cycle(t_data *data, t_carriage *current)
{
	t_op_s op;

	if (current->cycles_to_wait < 0)
		set_ope_code(data, current);
	if (current->cycles_to_wait == 0)
	{
		current->bytes_to_jump = 1;
		do_ope(current->opcode, data, current, &op);
		if (data->vm.verbose & 0b010000)
			print_pc_movements(data, current);
		current->pos = get_pos(current->pos + current->bytes_to_jump);
		current->bytes_to_jump = 0;
	}
}

void		do_cycles(t_data *data)
{
	t_carriage *current;

	while (data->carriages)
	{
		if (data->vm.dump != 0 && data->vm.cycle_to_dump
			== data->vm.nb_cycles)
			dump_memory(data);
		current = data->carriages;
		data->vm.nb_cycles++;
		data->vm.cycles_since_last_check++;
		if (data->vm.verbose & 0b010)
			print_cycle(data);
		while (current)
		{
			current->cycles_to_wait--;
			do_current_cycle(data, current);
			current = current->next;
		}
		if (data->vm.cycles_since_last_check == data->vm.cycle_to_die ||
			data->vm.cycle_to_die <= 0)
			do_check(data);
	}
}
