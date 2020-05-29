/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 19:25:29 by plagache          #+#    #+#             */
/*   Updated: 2020/05/30 00:08:16 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "op.h"
#include "asm.h"
#include "libft.h"
#include "ft_printf.h"

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
		else if (ret == GARBAGE || ret == QUOTES || ret == TOO_LONG)
			return (ret);
		if ((ret = is_header_comment(file->lines[counter])) == SUCCESS)
			fill_header(file->lines[counter], file, COMMENT, counter);
		else if (ret == GARBAGE || ret == QUOTES || ret == TOO_LONG)
			return (ret);
	}
	file->header->magic = COREWAR_EXEC_MAGIC;
	if (file->header->comment[0] == '\0' || file->header->prog_name[0] == '\0')
		return (FAILURE);
	return (SUCCESS);
}

int		handle_parse_error(int ret, t_file *file)
{
	if (ret == SUCCESS)
		return (SUCCESS);
	if (ret == FAILURE || ret == GARBAGE)
		ft_dprintf(STDERR_FILENO, "Syntax error\n");
	if (ret == TOO_LONG)
		ft_dprintf(STDERR_FILENO, "Champion name too long (Max Lenght %i)\n",
			PROG_NAME_LENGTH);
	if (ret == QUOTES)
		ft_dprintf(STDERR_FILENO, "Wrong number of quotes\n");
	free_arr((void**)file->lines);
	free(file->content);
	return (FAILURE);
}

int		whitespace_header(t_file *file)
{
	int		iterator;

	iterator= 0;
	while (iterator < file->line)
	{
		if (is_header_name(file->lines[iterator]) == SUCCESS
			|| is_header_comment(file->lines[iterator]) == SUCCESS)
			iterator++;
		if (whitespace(file->lines[iterator], ft_strlen(file->lines[iterator]))
			== FAILURE)
		{
			ft_dprintf(STDERR_FILENO, "Error on line |%s|\n",
						file->lines[iterator]);
			free_arr((void**)file->lines);
			free(file->content);
			return (FAILURE);
		}
		iterator++;
	}
	return (SUCCESS);
}

/*
** 3) set label, op_str, op for each lines
** get_label/op_str/op
** 4) check param validity using op and labels
** is_dir/reg/ind
** 5) create OCP and set size
** 6) get values
*/

int		parse_file(t_file *file, t_header *header)
{
	ft_memset(header, '\0', sizeof(t_header));
	file->header = header;
	if (handle_parse_error(parse_header(file), file) == FAILURE)
		return (FAILURE);
	if (whitespace_header(file) == FAILURE)
		return (FAILURE);
	if (parse_op(file) == FAILURE)
	{
		free_arr((void**)file->lines);
		free(file->content);
		return (FAILURE);
	}
	free(file->cor);
	free_arr((void**)file->lines);
	free(file->content);
	return (SUCCESS);
}
