/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nminit_to_zero.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:57:05 by nabboufe          #+#    #+#             */
/*   Updated: 2019/04/08 15:07:52 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/math.h"
#include <string.h>

t_matrix		*minit_to_zero(t_matrix *z_matrix, const unsigned int z)
{
	unsigned int x;
	unsigned int y;

	x = 0;
	y = 0;
	if (!(z_matrix))
		return (NULL);
	while (y < (*z_matrix).columns)
	{
		(*z_matrix).matrix[z][y][x] = 0;
		x++;
		if (x == (*z_matrix).lines)
		{
			x = 0;
			y++;
		}
	}
	return (z_matrix);
}

t_matrix		*nminit_to_zero(t_matrix *n_matrix)
{
	unsigned int	i;

	i = 0;
	while (i < (*n_matrix).nb_matrix)
		minit_to_zero(n_matrix, i);
	return (n_matrix);
}
