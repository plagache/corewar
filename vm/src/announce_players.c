/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   announce_players.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 15:33:32 by agardina          #+#    #+#             */
/*   Updated: 2020/06/03 15:33:33 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	announce_players(t_data *data)
{
	uint8_t i;

	i = 0;
	printf("Introducing contestants...\n");
	while (i < MAX_PLAYERS)
	{
		if (data->players[i].num > 0)
			printf("* Player %u, weighing %u bytes, \"%s\" (\"%s\") !\n"
			, data->players[i].num, data->players[i].code_size,
			data->players[i].name, data->players[i].comment);
		i++;
	}
}
