/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_cycles.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 12:35:30 by agardina          #+#    #+#             */
/*   Updated: 2020/06/04 12:35:31 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

static void	do_check(t_data *data)
{
	t_carriage *current;

	if (data->vm.cycle_to_die <= 0)
		delete_all_carriages(data);
	current = data->carriages;
	while (current)
	{
		if (data->vm.cycle_to_die <= data->vm.nb_cycles - current->last_live)
			current = delete_one_carriage(data, current);
		else
			current = current->next;
	}
	if (NBR_LIVE <= data->vm.nb_live || MAX_CHECKS <= data->vm.nb_checks)
	{
		data->vm.cycle_to_die -= CYCLE_DELTA;
		data->vm.nb_checks = 0;
	}
	else
		data->vm.nb_checks++;
	data->vm.nb_live = 0;
	data->vm.cycles_since_last_check = 0;
}

static void	set_ope_code(t_carriage *current, int32_t opcode)
{
	static const int	waiting_time[16] = {10, 5, 5, 10, 10, 6, 6, 6, 20,
	25, 25, 800, 10, 50, 1000, 2};

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
	int32_t opcode;

	opcode = get_from_ram(data, current->pos, 1);
	if (current->cycles_to_wait < 0)
		set_ope_code(current, opcode);
	if (current->cycles_to_wait == 0)
	{
		if (0x01 <= opcode && opcode <= 0x0b)
		{
			current->bytes_to_jump = 1;
			do_ope(opcode, data, current);
			current->pos = get_pos(current->pos + current->bytes_to_jump);
			current->bytes_to_jump = 0;
		}
		else
			current->pos = get_pos(current->pos + 1);
	}
}

void		do_cycles(t_data *data)
{
	t_carriage *current;

	while (data->carriages)
	{
		current = data->carriages;
		data->vm.nb_cycles++;
		while (current)
		{
			current->cycles_to_wait--;
			do_current_cycle(data, current);
			current = current->next;
		}
		if (data->vm.cycles_since_last_check == data->vm.cycle_to_die ||
			data->vm.cycle_to_die <= 0)
			do_check(data);
		else
			data->vm.cycles_since_last_check++;
	}
}
