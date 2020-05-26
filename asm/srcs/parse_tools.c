/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 10:29:19 by plagache          #+#    #+#             */
/*   Updated: 2020/05/26 11:58:05 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"
#include "op.h"

int		whitespace(char *str, int len)
{
	int counter;

	counter = -1;
	while (++counter < len && str[counter])
	{
		if (ft_strchr(WHITESPACE, str[counter]) != NULL)
			return (FAILURE);
	}
	return (SUCCESS);
}

int		is_header_name(char *str)
{
	char	*dot;
	char	*quote_one;
	char	*quote_two;

	dot = ft_strchr(str, '.');
	if (dot == NULL || ft_strncmp(dot, NAME_CMD_STRING, 5) != 0)
		return (FAILURE);
	if (whitespace(str, dot - str) == FAILURE)
		return (FAILURE);
	if (occurrence_of(dot + 5, '"') != 2)
		return (FAILURE);
	quote_one = ft_strchr(dot + 5, '"');
	quote_two = ft_strchr(quote_one, '"');
	if (((quote_two - quote_one) - 1) > PROG_NAME_LENGTH ||
		whitespace(quote_two + 1, (ft_strlen(str) - (quote_two + 1 - str)))
		== FAILURE)	
		return (FAILURE);
	return (SUCCESS);
}

int		is_header_comment(char *str)
{
	char	*dot;
	char	*quote_one;
	char	*quote_two;

	dot = ft_strchr(str, '.');
	if (dot == NULL || ft_strncmp(dot, COMMENT_CMD_STRING, 8) != 0)
		return (FAILURE);
	if (occurrence_of(dot + 8, '"') != 2)
		return (FAILURE);
	quote_one = ft_strchr(dot + 8, '"');
	quote_two = ft_strchr(quote_one, '"');
	if (((quote_two - quote_one) - 1) > COMMENT_LENGTH ||
		whitespace(quote_two + 1, (ft_strlen(str) - (quote_two + 1 - str)))
		== FAILURE)	
		return (FAILURE);
	return (SUCCESS);
}