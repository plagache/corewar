/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   announce_players.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <alagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 15:33:32 by agardina          #+#    #+#             */
/*   Updated: 2020/06/15 12:51:43 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	announce_players(t_data *data)
{
	uint8_t i;

	i = 0;
	ft_printf("Introducing contestants...\n");
	while (i < MAX_PLAYERS)
	{
		if (data->players[i].num > 0)
			ft_printf("* Player %u, weighing %u bytes, \"%s\" (\"%s\") !\n"
			, data->players[i].num, data->players[i].code_size,
			data->players[i].name, data->players[i].comment);
		i++;
	}
}
