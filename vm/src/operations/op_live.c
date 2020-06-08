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

static void	declare_live(t_data *data, int32_t num)
{
	data->vm.last_player_live = num;
}

int32_t		op_live(t_data *data, t_carriage *current)
{
	int32_t		arg;

	data->vm.nb_live++;
	current->last_live = data->vm.nb_cycles;
	arg = (uint32_t)(get_from_ram(data, current->pos + 1, 1)) << 24;
	arg += (uint32_t)(get_from_ram(data, current->pos + 2, 1)) << 16;
	arg += (uint32_t)(get_from_ram(data, current->pos + 3, 1)) << 8;
	arg += (uint32_t)(get_from_ram(data, current->pos + 4, 1));
	arg *= -1;
	current->bytes_to_jump += 4;
	if (1 <= arg && arg <= MAX_PLAYERS)
	{
		if (data->players[arg - 1].num != 0)
			declare_live(data, arg);
	}
	return (0);
}
