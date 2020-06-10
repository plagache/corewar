/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   announce_winner.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <alagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 14:52:15 by agardina          #+#    #+#             */
/*   Updated: 2020/06/10 09:49:04 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	announce_winner(t_data *data)
{
	uint8_t	num;

	num = data->vm.last_player_live;
	ft_printf("Contestant %u, \"%s\", has won !\n", num,
		data->players[num - 1].name);
}
