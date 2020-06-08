/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_arena.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 14:54:19 by agardina          #+#    #+#             */
/*   Updated: 2020/06/05 14:54:19 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	prepare_arena(t_data *data)
{
	t_carriage *c;

	c = data->carriages;
	while (c)
	{
		ft_memcpy(&(data->vm.arena[c->pos]), data->players[c->num - 1].code,
			data->players[c->num - 1].code_size);
		c = c->next;
	}
}
