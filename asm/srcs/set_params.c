/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agache <alagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 18:59:44 by alagache          #+#    #+#             */
/*   Updated: 2020/06/02 19:39:09 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "unistd.h"
#include "op.h"
#include "asm.h"
#include "libft.h"
#include "ft_printf.h"
#include "manage_error.h"

int check_content(t_cor *array, t_cor *cell, int param_nb, int code)
{
	int		iterator;
	int 	iter_arr;

	iterator = (code == DIR_CODE || code == REG_CODE ? 1 : 0);
	if (cell->params[param_nb][iterator] != LABEL_CHAR)
	{
		iterator += (cell->params[param_nb][iterator] == '-' ? 1 : 0);
		while (ft_isdigit(cell->params[param_nb][iterator]) == TRUE)
			iterator++;
		if (iterator == (int)ft_strlen(cell->params[param_nb]))
			return (SUCCESS);
	}
	if (code != REG_CODE && cell->params[param_nb][iterator] == LABEL_CHAR)
	{
		iter_arr = -1;
		while ((array + (++iter_arr))->line != NULL)
		{
			if ((array + iter_arr)->label != NULL
				&& ft_strcmp((array + iter_arr)->label,
						cell->params[param_nb] + 1 + iterator) == (':' - '\0'))
				return (SUCCESS);
		}
	}
	return (FAILURE);
}

void	wrong_param_content(t_cor *cell, int iterator)
{
	ft_dprintf(STDERR_FILENO, WRONG_PARAM, iterator + 1, cell->params[iterator],
				cell->op->keyword);
}

//iterate over nbr_arg parameter,
//	//call check_content to check validity of param content
//	//get_value of param
int set_param(t_cor *array, t_cor *cell)
{
	int iterator;
	int code;

	iterator = -1;
	while (++iterator < cell->op->nbr_arg)
	{
		code = ((cell->ocp << (2 * iterator)) >> 6) & 0b11;
		if (check_content(array, cell, iterator, code) == FAILURE)
		{
			wrong_param_content(cell, iterator);
			return (FAILURE);
		}
	}
	return (SUCCESS);
}

int	set_sizes(t_cor *cor, t_cor *array)
{
	int size;
	int	iterator;
	int	param;

	size = (cor->op->nbr_arg != 1
			|| cor->op->instruction_op_code == 16 ? 2 : 1);
	param = 0;
	iterator = -1;
	while (++iterator < cor->op->nbr_arg)
	{
		if ((((cor->ocp << (2 * iterator)) >> 6) & 0b11) == REG_CODE)
			param += 1;
		if ((((cor->ocp << (2 * iterator)) >> 6) & 0b11) == IND_CODE)
			param += 2;
		if ((((cor->ocp << (2 * iterator)) >> 6) & 0b11) == DIR_CODE)
			param += (cor->op->direct_size == 1 ? 2 : 4);
	}
	cor->size = size + param;
	cor->inc_size = (cor == array ? 0 :
					(cor - 1)->inc_size + (cor - 1)->size);
	return (SUCCESS);
}

//iterate over cor array and set param values according to OCP
//reg are followed only by numbers
//direct and indirect are only numbers or label
int set_params(t_cor *cor)
{
	int iterator;

	iterator = -1;
	while ((cor + (++iterator))->line != NULL)
	{
		if ((cor + iterator)->op != NULL)
		{
			set_sizes(cor + iterator, cor);
			if (set_param(cor, cor + iterator) == FAILURE)
				return (FAILURE);
		}
	}
	return (SUCCESS);
}
