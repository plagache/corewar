/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nminit_to_one.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:57:24 by nabboufe          #+#    #+#             */
/*   Updated: 2019/04/08 15:07:54 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/math.h"
#include <string.h>

t_matrix		*minit_to_one(t_matrix *o_matrix, const unsigned int z)
{
	unsigned int x;
	unsigned int y;

	x = 0;
	y = 0;
	if (!(o_matrix))
		return (NULL);
	while (y < (*o_matrix).columns)
	{
		(*o_matrix).matrix[z][y][x] = 1;
		x++;
		if (x == (*o_matrix).lines)
		{
			x = 0;
			y++;
		}
	}
	return (o_matrix);
}

t_matrix		*nminit_to_one(t_matrix *n_matrix)
{
	unsigned int i;

	i = 0;
	while (i < (*n_matrix).nb_matrix)
		minit_to_one(n_matrix, i++);
	return (n_matrix);
}
