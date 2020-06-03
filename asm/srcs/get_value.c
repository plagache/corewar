/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_value.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <alagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 19:19:45 by alagache          #+#    #+#             */
/*   Updated: 2020/06/03 23:42:30 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"
#include "asm.h"
#include "libft.h"
#include "ft_printf.h"

void	 get_value(t_cor *array, t_cor *cell, int param_nb, int code)
{
	int		iterator;
	int 	iter_arr;

	iterator = (code == DIR_CODE || code == REG_CODE ? 1 : 0);
	if (cell->params[param_nb][iterator] != LABEL_CHAR)
	{
		cell->value[param_nb] = ft_atoi(cell->params[param_nb] + iterator); 
	}
	if (code != REG_CODE && cell->params[param_nb][iterator] == LABEL_CHAR)
	{
		iter_arr = -1;
		while ((array + (++iter_arr))->line != NULL)
		{
			if ((array + iter_arr)->label != NULL
				&& ft_strcmp((array + iter_arr)->label,
					cell->params[param_nb] + 1 + iterator) == (':' - '\0'))
				cell->value[param_nb] = (array + iter_arr)->inc_size - cell->inc_size;
		}
	}
	ft_printf("%i\n", cell->value[param_nb]);
}

void	iter_params(t_cor *array, t_cor *cell)
{
	int iterator;
	int code;

	iterator = -1;
	while (++iterator < cell->op->nbr_arg)
	{
		code = ((cell->ocp << (2 * iterator)) >> 6) & 0b11;
		get_value(array, cell, iterator, code);
	}
}

void	get_values(t_cor *cor)
{
	int iterator;

	iterator = -1;
	while ((cor + (++iterator))->line != NULL)
	{
		if ((cor + iterator)->op != NULL)
			iter_params(cor, cor + iterator);
	}
}
