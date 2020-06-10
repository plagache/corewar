/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_carriages.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 15:34:34 by agardina          #+#    #+#             */
/*   Updated: 2020/06/10 17:05:51 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

static void	add_head_carriage(t_data *data)
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
}

static void	init_carriage(t_data *data, uint32_t num, uint32_t nb_carriages)
{
	data->carriages->num = num + 1;
	data->carriages->pos = (MEM_SIZE / data->vm.nb_players)
	* (data->vm.nb_players - nb_carriages);
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
			nb_carriages++;
			init_carriage(data, i, nb_carriages);
		}
		i++;
	}
	data->vm.last_player_live = data->carriages->num;
}
