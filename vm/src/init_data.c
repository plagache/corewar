/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <alagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 15:34:24 by agardina          #+#    #+#             */
/*   Updated: 2020/06/15 12:42:13 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

static void	init_vm(t_data *data)
{
	data->vm.nb_cycles = 0;
	data->vm.cycle_to_die = CYCLE_TO_DIE;
	data->vm.cycle_to_dump = 0;
	data->vm.cycles_since_last_check = 0;
	data->vm.dump = 0;
	data->vm.nb_process_since_beginning = 0;
	data->vm.verbose = 0;
	data->vm.aff = false;
}

static void	init_player(t_data *data)
{
	data->vm.nb_players = 0;
	data->players[0].num = 0;
	data->players[1].num = 0;
	data->players[2].num = 0;
	data->players[3].num = 0;
}

void		init_data(t_data *data)
{
	init_vm(data);
	init_player(data);
	data->carriages = NULL;
}
