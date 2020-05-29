/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 10:29:19 by plagache          #+#    #+#             */
/*   Updated: 2020/05/29 19:22:52 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"
#include "op.h"
#include "ft_printf.h"

int			whitespace(char *str, int len)
{
	int counter;

	counter = -1;
	while (++counter < len && str[counter])
	{
		if (ft_strchr(WHITESPACE, str[counter]) == NULL)
			return (FAILURE);
	}
	return (SUCCESS);
}

int			is_header_name(char *str)
{
	char	*dot;
	char	*quote_one;
	char	*quote_two;

	dot = ft_strchr(str, '.');
	if (dot == NULL)
		return (NO_DOT);
	if (ft_strncmp(dot, NAME_CMD_STRING, 5) != 0)
		return (NO_NAME);
	if (whitespace(str, dot - str) == FAILURE)
		return (GARBAGE);
	if (occurrence_of(dot + 5, '"') != 2)
		return (QUOTES);
	quote_one = ft_strchr(dot + 5, '"');
	quote_two = ft_strchr(quote_one + 1, '"');
	if (whitespace(dot + 5, quote_one - (dot + 5)) == FAILURE)
		return (GARBAGE);
	if (((quote_two - quote_one) - 1) > PROG_NAME_LENGTH)
		return (TOO_LONG);
	if (whitespace(quote_two + 1, (ft_strlen(str) - (quote_two + 1 - str)))
		== FAILURE)
		return (GARBAGE);
	return (SUCCESS);
}

int			is_header_comment(char *str)
{
	char	*dot;
	char	*quote_one;
	char	*quote_two;

	dot = ft_strchr(str, '.');
	if (dot == NULL)
		return (NO_DOT);
	if (ft_strncmp(dot, COMMENT_CMD_STRING, 8) != 0)
		return (NO_NAME);
	if (whitespace(str, dot - str) == FAILURE)
		return (GARBAGE);
	if (occurrence_of(dot + 8, '"') != 2)
		return (QUOTES);
	quote_one = ft_strchr(dot + 8, '"');
	quote_two = ft_strchr(quote_one + 1, '"');
	if (whitespace(dot + 8, quote_one - (dot + 8)) == FAILURE)
		return (GARBAGE);
	if (((quote_two - quote_one) - 1) > COMMENT_LENGTH)
		return (TOO_LONG);
	if (whitespace(quote_two + 1, (ft_strlen(str) - (quote_two + 1 - str)))
		== FAILURE)
		return (GARBAGE);
	return (SUCCESS);
}

void		fill_header(char *str, t_header *header, int code)
{
	char	*quote1;
	char	*quote2;

	quote1 = ft_strchr(str, '"');
	quote2 = ft_strchr(quote1 + 1, '"');
	if (code == NAME)
		ft_strncpy(header->prog_name, quote1 + 1, (quote2 - 1) - quote1);
	else
		ft_strncpy(header->comment, quote1 + 1, (quote2 - 1) - quote1);
}
