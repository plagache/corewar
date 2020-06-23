/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_live.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 14:50:59 by agardina          #+#    #+#             */
/*   Updated: 2020/06/05 14:51:00 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

static void	declare_player_live(t_data *data, int32_t num)
{
	data->vm.last_player_live = num;
	if (data->vm.verbose & 0b01)
		ft_printf("Player %d (%s) is said to be alive\n", num,
			data->players[num - 1].name);
}

int32_t		op_live(t_data *data, t_carriage *current, t_op_s *op)
{
	int32_t		arg;

	op->nb_arg = 0;
	op->dir_size = SMALL_DIR;
	op->idx_mod = true;
	data->vm.nb_live++;
	current->last_live = data->vm.nb_cycles;
	arg = (uint32_t)(get_from_ram(data, current->pos + 1, 1)) << 24;
	arg += (uint32_t)(get_from_ram(data, current->pos + 2, 1)) << 16;
	arg += (uint32_t)(get_from_ram(data, current->pos + 3, 1)) << 8;
	arg += (uint32_t)(get_from_ram(data, current->pos + 4, 1));
	if (data->vm.verbose & 0b0100)
	{
		print_proc_and_ft(current);
		ft_printf("%d\n", arg);
	}
	arg *= -1;
	current->bytes_to_jump += 4;
	if (1 <= arg && arg <= MAX_PLAYERS)
	{
		if (data->players[arg - 1].num != 0)
			declare_player_live(data, arg);
	}
	return (0);
}
