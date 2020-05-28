/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 19:25:29 by plagache          #+#    #+#             */
/*   Updated: 2020/05/28 19:27:33 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "op.h"
#include "asm.h"
#include "libft.h"
#include "ft_printf.h"

int		parse_header(t_file *file)
{
	int counter;
	int ret;

	counter = -1;
	while (file->lines[++counter])
	{
		if ((ret = is_header_name(file->lines[counter])) == SUCCESS)
			fill_header(file->lines[counter], file->header, NAME);
		else if (ret == GARBAGE || ret == QUOTES || ret == TOO_LONG)
			return (ret);
		if ((ret = is_header_comment(file->lines[counter])) == SUCCESS)
			fill_header(file->lines[counter], file->header, COMMENT);
		else if (ret == GARBAGE || ret == QUOTES || ret == TOO_LONG)
			return (ret);
	}
	if (file->header->comment[0] == '\0' || file->header->prog_name[0] == '\0')
		return (FAILURE);
	return (SUCCESS);
}

int		handle_parse_error(int ret)
{
	if (ret == FAILURE || ret == GARBAGE)
		ft_dprintf(STDERR_FILENO, "Syntax error\n");
	if (ret == TOO_LONG)
		ft_dprintf(STDERR_FILENO, "Champion name too long (Max Lenght %i)\n",
			PROG_NAME_LENGTH);
	if (ret == QUOTES)
		ft_dprintf(STDERR_FILENO, "Wrong number of quotes\n");
	if (ret == SUCCESS)
		return (SUCCESS);	
	return (FAILURE);
}

int		parse_file(t_file *file, t_header *header, t_cor *cor)
{
	ft_memset(header, '\0', sizeof(t_header));
	ft_memset(cor, '\0', sizeof(t_cor));
	file->header = header;
	file->cor = cor;
	if (handle_parse_error(parse_header(file)) == FAILURE)
		return (FAILURE);
	ft_printf("progname = |%s|\nprogcomment = |%s|\n", header->prog_name, header->comment);
	return (SUCCESS);
}