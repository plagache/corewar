/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_carriages.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <alagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 15:34:34 by agardina          #+#    #+#             */
/*   Updated: 2020/06/15 12:50:16 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void		add_head_carriage(t_data *data)
{
	t_carriage	*new;

	if (!(new = (t_carriage*)malloc(sizeof(t_carriage))))
		deal_error(data, "", NO_USAGE);
	ft_bzero(new, sizeof(t_carriage));
	if (data->carriages)
	{
		data->carriages->previous = new;
		new->next = data->carriages;
	}
	data->carriages = new;
	data->vm.nb_process += 1;
	data->vm.nb_process_since_beginning += 1;
}

static void	init_carriage(t_data *data, uint32_t nb_carriages)
{
	data->carriages->num = data->vm.nb_process_since_beginning;
	data->carriages->pos = (MEM_SIZE / data->vm.nb_players) * nb_carriages;
	data->carriages->reg[0] = -(data->carriages->num);
}

void		prepare_carriages(t_data *data)
{
	uint8_t		i;
	uint32_t	nb_carriages;

	i = 0;
	nb_carriages = 0;
	while (i < MAX_PLAYERS)
	{
		if (data->players[i].num > 0)
		{
			add_head_carriage(data);
			init_carriage(data, nb_carriages);
			nb_carriages++;
		}
		i++;
	}
	data->vm.last_player_live = data->carriages->num;
}
