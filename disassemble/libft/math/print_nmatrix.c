/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_nmatrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:56:45 by nabboufe          #+#    #+#             */
/*   Updated: 2019/04/08 15:07:50 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/math.h"

void	print_matrix(t_matrix *p_matrix, const unsigned int z)
{
	unsigned int x;
	unsigned int y;

	x = 0;
	y = 0;
	if (!(p_matrix))
		return ;
	while (y < (*p_matrix).columns)
	{
		ft_putchar(' ');
		ft_putnbr((*p_matrix).matrix[z][y][x]);
		x++;
		if (x != (*p_matrix).lines)
			ft_putstr("  -  ");
		else
			ft_putstr("  |  ");
		if (x == (*p_matrix).lines)
		{
			x = 0;
			y++;
			ft_putchar('\n');
		}
	}
	ft_putstr("End of the matrix\n");
}

void	print_nmatrix(t_matrix *n_matrix)
{
	unsigned int i;

	i = 0;
	while (i < (*n_matrix).nb_matrix)
	{
		ft_putstr("Matrix number ");
		ft_putnbr(i + 1);
		ft_putstr(" :\n");
		print_matrix(n_matrix, i);
		ft_putstr("---- ~~~~ ----\n");
		i++;
	}
}
