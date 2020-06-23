/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 14:50:35 by agardina          #+#    #+#             */
/*   Updated: 2020/06/05 14:50:36 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

static void	verbose_fork_lfork(t_data *data, t_carriage *current,
	int16_t shift)
{
	if ((data->vm.verbose & 0b0100) == 0)
		return ;
	print_proc_and_ft(current);
	ft_printf("%d (%d)\n", shift, get_pos(current->pos + shift));
}

void		config_fork_carriage(t_data *data, t_carriage *current,
	int32_t param)
{
	int32_t	i;

	i = 0;
	data->carriages->bytes_to_jump = 0;
	data->carriages->carry = current->carry;
	data->carriages->cycles_to_wait = -1;
	data->carriages->last_live = current->last_live;
	data->carriages->num = data->vm.nb_process_since_beginning;
	data->carriages->pos = get_pos(current->pos + param);
	while (i < REG_NUMBER)
	{
		data->carriages->reg[i] = current->reg[i];
		i++;
	}
}

int32_t		op_lfork(t_data *data, t_carriage *current, t_op_s *op)
{
	int16_t shift;

	op->nb_arg = 0;
	op->dir_size = SMALL_DIR;
	op->idx_mod = true;
	shift = get_from_ram(data, current->pos + 1, 2);
	add_head_carriage(data);
	config_fork_carriage(data, current, shift);
	current->bytes_to_jump += 2;
	verbose_fork_lfork(data, current, shift);
	return (0);
}

int32_t		op_fork(t_data *data, t_carriage *current, t_op_s *op)
{
	int16_t shift;

	op->nb_arg = 0;
	op->dir_size = SMALL_DIR;
	op->idx_mod = true;
	shift = get_from_ram(data, current->pos + 1, 2);
	add_head_carriage(data);
	config_fork_carriage(data, current, shift % IDX_MOD);
	current->bytes_to_jump += 2;
	verbose_fork_lfork(data, current, shift % IDX_MOD);
	return (0);
}
