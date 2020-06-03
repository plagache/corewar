/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <alagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 19:25:29 by plagache          #+#    #+#             */
/*   Updated: 2020/06/03 23:36:17 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "op.h"
#include "asm.h"
#include "libft.h"
#include "ft_printf.h"
#include "manage_error.h"

int		whitespace_header(t_file *file)
{
	int		iterator;

	iterator = 0;
	while (iterator < file->line)
	{
		if (is_header_name(file->lines[iterator]) == SUCCESS
			|| is_header_comment(file->lines[iterator]) == SUCCESS)
			iterator++;
		else if (whitespace(file->lines[iterator], ft_strlen(file->lines[iterator]))
			== FAILURE)
		{
			ft_dprintf(STDERR_FILENO, WS_HEADER, file->lines[iterator]);
			return (FAILURE);
		}
		iterator++;
	}
	return (SUCCESS);
}

int		parse_header(t_file *file)
{
	int counter;
	int ret;

	counter = -1;
	file->line = -1;
	while (file->lines[++counter])
	{
		if ((ret = is_header_name(file->lines[counter])) == SUCCESS)
			fill_header(file->lines[counter], file, NAME, counter);
		else if (ret == GARBAGE || ret == QUOTES || ret == TOO_LONG_NAME)
			return (ret);
		if ((ret = is_header_comment(file->lines[counter])) == SUCCESS)
			fill_header(file->lines[counter], file, COMMENT, counter);
		else if (ret == GARBAGE || ret == QUOTES || ret == TOO_LONG_COMMENT)
			return (ret);
	}
	file->header->magic = COREWAR_EXEC_MAGIC;
	if (file->header->comment[0] == '\0' || file->header->prog_name[0] == '\0')
		return (FAILURE);
	if (whitespace_header(file) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

int		handle_parse_error(int ret, t_file *file)
{
	if (ret == SUCCESS)
		return (SUCCESS);
	if (ret == FAILURE || ret == GARBAGE)
		ft_dprintf(STDERR_FILENO, SYNTAX);
	if (ret == TOO_LONG_NAME)
		ft_dprintf(STDERR_FILENO, LONG_NAME, PROG_NAME_LENGTH);
	if (ret == TOO_LONG_COMMENT)
		ft_dprintf(STDERR_FILENO, LONG_COMMENT, COMMENT_LENGTH);
	if (ret == QUOTES)
		ft_dprintf(STDERR_FILENO, ERR_QUOTES);
	free_arr((void**)file->lines);
	free(file->content);
	return (FAILURE);
}

/*
** lexer parser
** !!\n in header
** 1) get values
** 1.1) wrong_param_content for error output in set_param
** 2) write
*/

int		parse_file(t_file *file, t_header *header)
{
	ft_memset(header, '\0', sizeof(t_header));
	file->header = header;
	if (handle_parse_error(parse_header(file), file) == FAILURE)
		return (FAILURE);
	if (parse_op(file) == FAILURE)
	{
		free_arr((void**)file->lines);
		free(file->content);
		return (FAILURE);
	}
	if (set_label_op(file->cor) == FAILURE
		|| set_params(file->cor) == FAILURE)
	{
		free(file->cor);
		free_arr((void**)file->lines);
		free(file->content);
		return (FAILURE);
	}
	get_values(file->cor);
	free(file->cor);
	free_arr((void**)file->lines);
	free(file->content);
	return (SUCCESS);
}
