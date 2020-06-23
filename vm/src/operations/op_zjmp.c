/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 14:51:59 by agardina          #+#    #+#             */
/*   Updated: 2020/06/05 14:51:59 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int32_t	op_zjmp(t_data *data, t_carriage *current, t_op_s *op)
{
	int16_t shift;

	op->nb_arg = 0;
	op->dir_size = SMALL_DIR;
	op->idx_mod = true;
	shift = get_from_ram(data, current->pos + 1, 2);
	shift %= IDX_MOD;
	if (data->vm.verbose & 0b0100)
	{
		print_proc_and_ft(current);
		ft_printf("%d ", shift);
	}
	if (current->carry == 0)
	{
		current->bytes_to_jump += 2;
		if (data->vm.verbose & 0b0100)
			ft_printf("FAILED\n");
		return (-1);
	}
	current->pos = get_pos(current->pos + shift);
	current->bytes_to_jump = 0;
	if (data->vm.verbose & 0b0100)
		ft_printf("OK\n");
	return (0);
}
