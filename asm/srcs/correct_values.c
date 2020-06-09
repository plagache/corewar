/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <alagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 05:58:32 by alagache          #+#    #+#             */
/*   Updated: 2020/06/09 14:41:31 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

int		swap_bytes(int value)
{
	long tmp;

	tmp = value;
	tmp = ((tmp & 0x0000ffff) << 16) | ((tmp & 0xffff0000) >> 16);
	tmp = (tmp & 0xffff0000) | ((tmp & 0x000000ff) << 8)
			| ((tmp & 0x0000ff00) >> 8);
	tmp = ((tmp & 0xff000000) >> 8) | ((tmp & 0x00ff0000) << 8)
			| (tmp & 0x0000ffff);
	value = tmp;
	return (value);
}

int		what_size(char direct_size, short ocp, int param_nb)
{
	if ((((ocp << (2 * param_nb)) >> 6) & 0b11) == REG_CODE)
		return (1);
	if ((((ocp << (2 * param_nb)) >> 6) & 0b11) == IND_CODE)
		return (2);
	if ((((ocp << (2 * param_nb)) >> 6) & 0b11) == DIR_CODE)
		return (direct_size == 0 ? 4 : 2);
	return (FAILURE);
}

int		correct_value(int size, int value)
{
	if (size == 2)
		return ((short)value);
	if (size == 1)
		return ((char)value);
	return (value);
}

int		correct_values(t_cor *cor)
{
	int size;
	int param_nb;
	int new_value;

	new_value = 0;
	param_nb = 0;
	while (param_nb < cor->op->nbr_arg)
	{
		if (cor->op->nbr_arg > 1)
			size = what_size(cor->op->direct_size, cor->ocp, param_nb);
		else
			size = cor->size - 1 - (cor->op->op_code == 16 ? 1 : 0);
		new_value = correct_value(size, cor->value[param_nb]);
		if (size == 1 && new_value > 99)
			return (FAILURE);
		new_value = swap_bytes(new_value);
		ft_memcpy(cor->val[param_nb], &new_value, sizeof(int));
		param_nb++;
	}
	return (SUCCESS);
}

int		correct_arr(t_cor *cor)
{
	int iterator;

	iterator = -1;
	while ((cor + (++iterator))->line != NULL)
	{
		if ((cor + iterator)->size != 0)
		{
			if (correct_values(cor + iterator) == FAILURE)
				return (FAILURE);
		}
	}
	return (SUCCESS);
}
