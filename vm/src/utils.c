/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 14:54:15 by agardina          #+#    #+#             */
/*   Updated: 2020/06/05 14:54:16 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void		write_in_ram(t_data *data, int32_t start, int32_t nb)
{
	int32_t i;

	i = 0;
	while (i < 4)
	{
		data->vm.arena[get_pos(start + i)] = (nb >> ((3 - i) * 8)) & 0xFF;
		i++;
	}
}

int32_t		get_pos(int32_t res)
{
	if (res < 0)
	{
		while (res < 0)
			res += MEM_SIZE;
		return (res);
	}
	return (res % MEM_SIZE);
}

uint32_t	get_from_ram(t_data *data, int32_t pos, int8_t len)
{
	int			i;
	uint32_t	res;

	i = 0;
	res = 0;
	while (i < len)
	{
		res = res << 8;
		res += data->vm.arena[get_pos(pos + i)];
		i++;
	}
	return (res);
}
