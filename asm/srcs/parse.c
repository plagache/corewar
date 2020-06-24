/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <alagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 19:25:29 by plagache          #+#    #+#             */
/*   Updated: 2020/06/24 02:28:04 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "asm.h"
#include "libft.h"
#include "ft_printf.h"
#include "manage_error.h"

static void	split_header(t_file *file)
{
	int	iterator;

	iterator = -1;
	file->len_header = ft_strlen(file->header_str);
	while (file->header_str[++iterator] != '\0')
	{
		if (file->header_str[iterator] == '\n')
			file->header_str[iterator] = '\0';
		else if (file->header_str[iterator] == '"')
		{
			iterator++;
			while (file->header_str[iterator] != '"')
				iterator++;
		}
		else if (ft_strchr(";#", file->header_str[iterator]) != NULL)
		{
			while (file->header_str[iterator] != '\n')
				file->header_str[iterator++] = '\0';
			file->header_str[iterator] = '\0';
		}
	}
}

static int	whitespace_header(t_file *file)
{
	int		iterator;
	int		ret;

	iterator = 0;
	while (iterator < (int)file->len_header)
	{
		if (is_header_name(file->header_str + iterator) == SUCCESS
			|| is_header_comment(file->header_str + iterator) == SUCCESS)
			iterator += ft_strlen(file->header_str + iterator);
		else if (whitespace(file->header_str + iterator,
					ft_strlen(file->header_str + iterator))
			== FAILURE)
		{
			ft_dprintf(STDERR_FILENO, WS_HEADER, file->header_str + iterator);
			return (FAILURE);
		}
		ret = ft_strlen(file->header_str + iterator);
		iterator += (ret == 0 ? 1 : ret);
	}
	return (SUCCESS);
}

static int	parse_header(t_file *file)
{
	int iterator;
	int ret;

	iterator = 0;
	while (iterator < (int)file->len_header)
	{
		if ((ret = is_header_name(file->header_str + iterator)) == SUCCESS)
			fill_header(file->header_str + iterator, file, NAME);
		else if (ret == GARBAGE || ret == QUOTES || ret == TOO_LONG_NAME)
			return (ret);
		if ((ret = is_header_comment(file->header_str + iterator)) == SUCCESS)
			fill_header(file->header_str + iterator, file, COMMENT);
		else if (ret == GARBAGE || ret == QUOTES || ret == TOO_LONG_COMMENT)
			return (ret);
		ret = ft_strlen(file->header_str + iterator);
		iterator += (ret == 0 ? 1 : ret);
	}
	file->header->magic = COREWAR_EXEC_MAGIC;
	if (file->header->comment[0] == '\0' || file->header->prog_name[0] == '\0')
		return (FAILURE);
	if (whitespace_header(file) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}

static int	handle_parse_error(int ret, t_file *file)
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
	free(file->header_str);
	return (FAILURE);
}

int			parse_file(t_file *file, t_header *header)
{
	ft_memset(header, '\0', sizeof(t_header));
	file->header = header;
	split_header(file);
	if (handle_parse_error(parse_header(file), file) == FAILURE)
		return (FAILURE);
	if (parse_op(file) == FAILURE)
	{
		free_arr((void**)file->lines);
		free(file->content);
		free(file->header_str);
		return (FAILURE);
	}
	if (set_label_op(file->cor) == FAILURE
		|| set_params(file->cor, file->header) == FAILURE)
	{
		free(file->cor);
		free_arr((void**)file->lines);
		free(file->content);
		free(file->header_str);
		return (FAILURE);
	}
	get_values(file->cor);
	return (SUCCESS);
}
