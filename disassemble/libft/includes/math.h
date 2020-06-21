/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:59:54 by nabboufe          #+#    #+#             */
/*   Updated: 2019/04/08 16:00:57 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_H
# define MATH_H

# include "libft.h"

typedef struct		s_matrix
{
	unsigned int	nb_matrix;
	unsigned int	columns;
	unsigned int	lines;
	int				***matrix;
}					t_matrix;

t_matrix			*n_matrix(unsigned int x, unsigned int y, unsigned int z);
void				print_nmatrix(t_matrix *p_matrix);
t_matrix			*nminit_to_zero(t_matrix *z_matrix);
t_matrix			*nminit_to_one_zero(t_matrix *zo_matrix);
t_matrix			*nminit_to_one(t_matrix *o_matrix);

#endif
