/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <alagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 16:52:30 by plagache          #+#    #+#             */
/*   Updated: 2020/06/03 23:16:48 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "op.h"
#include "asm.h"
#include "libft.h"
#include "ft_printf.h"
#include "manage_error.h"

static void	wrong_parameter(int nb, char param_code, char *str)
{
	if (param_code == 0)
		ft_dprintf(STDERR_FILENO, NOT_PARAM, nb + 1, str);
	if (param_code == DIR_CODE)
		ft_dprintf(STDERR_FILENO, INVALID_TYPE, nb + 1, "direct", str);
	if (param_code == IND_CODE)
		ft_dprintf(STDERR_FILENO, INVALID_TYPE, nb + 1, "indirect", str);
	if (param_code == REG_CODE)
		ft_dprintf(STDERR_FILENO, INVALID_TYPE, nb + 1, "register", str);
}

int			check_ocp(t_cor *cor)
{
	char	test;
	int		iterator;

	iterator = 0;
	while (iterator < cor->op->nbr_arg)
	{
		test = ((cor->ocp << (2 * iterator)) >> 6) & 0b11;
		if (((cor->op->type_arr[iterator] >> (test - 1)) & 1) == 0)
		{
			wrong_parameter(iterator, test, cor->op->keyword);
			return (FAILURE);
		}
		iterator++;
	}
	return (SUCCESS);
}

static int	what_type(char *str)
{
	int counter;

	counter = 0;
	while (str[counter] != '\0' && ft_strchr(PARAMS_CHAR, str[counter]))
		counter++;
	if (str[counter] != '\0')
		return (FAILURE);
	if (str[0] == '%')
		return (DIR_CODE);
	if (str[0] == 'r')
		return (REG_CODE);
	return (IND_CODE);
}

char		gen_ocp(t_cor *cor)
{
	int		counter;
	int		type;

	counter = 0;
	while (counter < cor->op->nbr_arg)
	{
		type = what_type(cor->params[counter]);
		if (type == FAILURE)
		{
			wrong_parameter(counter, 0, cor->op->keyword);
			return (FAILURE);
		}
		cor->ocp ^= type << ((3 - counter) * 2);
		counter++;
	}
	return (SUCCESS);
}
