/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_op_tool.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <alagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 18:19:12 by plagache          #+#    #+#             */
/*   Updated: 2020/06/08 17:01:39 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "asm.h"
#include "ft_printf.h"
#include "manage_error.h"

int		is_op(char *str)
{
	int		iterator;
	int		found;
	size_t	len_key;
	t_op	op;

	while (ft_strchr(WHITESPACE, *str) != NULL)
		str++;
	iterator = NB_OF_INSTRUCTION;
	found = 0;
	while (found == 0 && --iterator >= 0)
	{
		op = g_op_tab[iterator];
		len_key = ft_strlen(op.keyword);
		if (ft_strncmp(str, op.keyword, len_key) == 0)
			found = 1;
	}
	if (found == 0)
		return (FAILURE);
	if (ft_strchr(WHITESPACE, *(str + len_key)) == NULL)
		return (FAILURE);
	if (occurrence_of(str + len_key, ',') != op.nbr_arg - 1)
		return (FAILURE);
	return (SUCCESS);
}

int		is_label(char *str)
{
	char *colon;

	if ((colon = ft_strchr(str, LABEL_CHAR)) == NULL)
		return (NOT_LABEL);
	while (*str != '\0' && ft_strchr(WHITESPACE, *str) != NULL)
		str++;
	while (*str != '\0' && ft_strchr(LABEL_CHARS, *str) != NULL)
		str++;
	if (colon == str)
		return (SUCCESS);
	return (NOT_LABEL);
}

int		valid_line(char *str)
{
	int		ret_label;
	int		ret_op;

	ret_label = is_label(str);
	if (ret_label == SUCCESS)
		str = ft_strchr(str, LABEL_CHAR) + 1;
	ret_op = is_op(str);
	if (ret_op == SUCCESS)
		return (SUCCESS);
	if (ret_label == SUCCESS && whitespace(str, ft_strlen(str)) == SUCCESS)
		return (SUCCESS);
	return (FAILURE);
}

void	fill_cor(t_file *file, int counter)
{
	int		iterator;
	int		cor_iter;

	iterator = 0;
	cor_iter = 0;
	while (counter > cor_iter && file->lines[iterator] != NULL)
	{
		if (valid_line(file->lines[iterator]) == SUCCESS)
		{
			file->cor[cor_iter].line = file->lines[iterator];
			cor_iter++;
		}
		iterator++;
	}
}

int		parse_op(t_file *file)
{
	int	iterator;
	int counter;

	iterator = 0;
	counter = 0;
	while (file->lines[iterator] != NULL)
	{
		if (valid_line(file->lines[iterator]) == SUCCESS)
			counter++;
		else if (whitespace(file->lines[iterator],
				ft_strlen(file->lines[iterator])) == FAILURE)
		{
			ft_dprintf(STDERR_FILENO, NON_EMPTY_LNE, file->lines[iterator]);
			return (FAILURE);
		}
		iterator++;
	}
	file->cor = ft_memalloc(sizeof(t_cor) * (counter + 1));
	if (file->cor == NULL)
		return (FAILURE);
	fill_cor(file, counter);
	return (SUCCESS);
}
