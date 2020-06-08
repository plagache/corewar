/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_label_op_params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <alagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 16:33:31 by alagache          #+#    #+#             */
/*   Updated: 2020/06/08 17:04:54 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "asm.h"
#include "libft.h"
#include "ft_printf.h"
#include "manage_error.h"

void	set_label(t_cor *cor)
{
	char *ptr;

	if ((ptr = ft_strchr(cor->line, LABEL_CHAR)) != NULL
		&& ft_strchr(SEP_CHARS, *(ptr - 1)) == NULL)
	{
		cor->label = cor->line;
		while (ft_strchr(WHITESPACE, *(cor->label)) != NULL)
			(cor->label)++;
	}
}

int		set_op(t_cor *cor)
{
	int		iterator;
	int		found;
	size_t	len_key;
	t_op	op;

	cor->op_str = cor->line;
	if (cor->label != NULL)
		cor->op_str = ft_strchr(cor->label, ':') + 1;
	while (ft_strchr(WHITESPACE, *(cor->op_str)) != NULL)
		cor->op_str++;
	if (*(cor->op_str) == '\0')
		return (NOT_OP);
	iterator = NB_OF_INSTRUCTION;
	found = 0;
	while (found == 0 && --iterator >= 0)
	{
		op = g_op_tab[iterator];
		len_key = ft_strlen(op.keyword);
		if (ft_strncmp(cor->op_str, op.keyword, len_key) == 0)
			found = 1;
	}
	cor->op = &(g_op_tab[iterator]);
	*(cor->op_str + len_key) = ',';
	return (SUCCESS);
}

int		clean_params(t_cor *cor)
{
	int	iterator;
	int	jterator;

	iterator = 0;
	while (++iterator <= cor->op->nbr_arg)
	{
		if (whitespace(cor->params[iterator - 1],
			ft_strlen(cor->params[iterator - 1])) == SUCCESS)
		{
			ft_dprintf(STDERR_FILENO, EMPTY_ARG);
			return (FAILURE);
		}
		while (ft_strchr(WHITESPACE, *(cor->params[iterator - 1])) != NULL)
			(cor->params[iterator - 1])++;
		jterator = ft_strlen(cor->params[iterator - 1]);
		while (ft_strchr(WHITESPACE, cor->params[iterator - 1][--jterator])
				!= NULL)
			cor->params[iterator - 1][jterator] = '\0';
	}
	return (SUCCESS);
}

int		set_params_str(t_cor *cor)
{
	int	iterator;

	iterator = 0;
	while (++iterator <= cor->op->nbr_arg)
	{
		if (iterator == 1)
			cor->params[iterator - 1] = ft_strchr(cor->op_str, ',') + 1;
		else
			cor->params[iterator - 1] =
				ft_strchr(cor->params[iterator - 2], ',') + 1;
	}
	iterator = 0;
	while (++iterator <= cor->op->nbr_arg)
		*(cor->params[iterator - 1] - 1) = '\0';
	if (clean_params(cor) == FAILURE
		|| gen_ocp(cor) == FAILURE
		|| check_ocp(cor) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int		set_label_op(t_cor *cor)
{
	int	iterator;

	iterator = -1;
	while ((cor + (++iterator))->line != NULL)
	{
		set_label(cor + iterator);
		if (set_op(cor + iterator) == SUCCESS)
		{
			if (set_params_str(cor + iterator) == FAILURE)
				return (FAILURE);
		}
	}
	return (SUCCESS);
}
