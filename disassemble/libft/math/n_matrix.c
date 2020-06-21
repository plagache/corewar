/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   n_matrix.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:57:51 by nabboufe          #+#    #+#             */
/*   Updated: 2019/04/08 15:59:45 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/math.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

t_matrix		*n_matrix(unsigned int x, unsigned int y, unsigned int z)
{
	t_matrix		*n_matrix;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (x == 0 || y == 0 || z == 0)
		return (NULL);
	n_matrix = (t_matrix *)malloc(sizeof(t_matrix));
	(*n_matrix).nb_matrix = z;
	(*n_matrix).columns = y;
	(*n_matrix).lines = x;
	if (!((*n_matrix).matrix = (int ***)malloc(sizeof(int **) * z)))
		return (NULL);
	while (i < z)
	{
		if (!((*n_matrix).matrix[i] = (int **)malloc(sizeof(int *) * y)))
			return (NULL);
		while (j < y)
			(*n_matrix).matrix[i][j++] = (int *)malloc(sizeof(int) * x);
		j = 0;
		i++;
	}
	return (n_matrix);
}
