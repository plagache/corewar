/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nminit_to_one_zero.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:57:42 by nabboufe          #+#    #+#             */
/*   Updated: 2019/04/08 15:07:56 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/math.h"
#include <string.h>
#include <unistd.h>

t_matrix		*minit_to_one_zero(t_matrix *zo_matrix, const unsigned int z)
{
	unsigned int x;
	unsigned int y;
	unsigned int d;

	x = 0;
	y = 0;
	d = 0;
	if (!(zo_matrix))
		return (NULL);
	while (y < (*zo_matrix).columns)
	{
		if (d % 2 != 1)
			(*zo_matrix).matrix[z][y][x] = 0;
		else
			(*zo_matrix).matrix[z][y][x] = 1;
		x++;
		d++;
		if (x == (*zo_matrix).lines)
		{
			x = 0;
			y++;
		}
	}
	return (zo_matrix);
}

t_matrix		*nminit_to_one_zero(t_matrix *n_matrix)
{
	unsigned int i;

	i = 0;
	while (i < (*n_matrix).nb_matrix)
		minit_to_one_zero(n_matrix, i++);
	return (n_matrix);
}
