/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <alagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 09:12:48 by plagache          #+#    #+#             */
/*   Updated: 2020/06/09 14:52:06 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "asm.h"
#include "manage_error.h"
#include "ft_printf.h"

static	void	del_comment(char *str)
{
	char	*ret;

	ret = ft_strchr(str, COMMENT_CHAR);
	if (ret != NULL)
		ret[0] = '\0';
	ret = ft_strchr(str, ALT_COMMENT_CHAR);
	if (ret != NULL)
		ret[0] = '\0';
}

static	int		split_content(t_file *file)
{
	char	*quote;
	size_t	len;

	if ((quote = ft_strrchr(file->content, '"')) == NULL
		|| (quote = ft_strchr(quote, '\n')) == NULL)
		return (FAILURE);
	len = quote - file->content + 1;
	file->header_str = ft_strsub(file->content, 0, len);
	if (file->header_str == NULL)
		return (FAILURE);
	file->lines = ft_strsplit(file->content + len, '\n');
	if (file->lines == NULL)
	{
		ft_printf(SPLIT_MALLOC);
		free(file->header_str);
		return (FAILURE);
	}
	return (SUCCESS);
}

static	int		fill_content(t_file *file)
{
	char	buff[BUFF_SIZE + 1];
	int		ret;

	file->content = ft_strnew(0);
	if (file->content == NULL)
		return (ERR_MALLOC);
	while ((ret = read(file->fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		file->content = ft_strjoinfree(file->content, buff, 1);
		if (file->content == NULL)
			return (ERR_MALLOC);
		if (ft_strlen(buff) != (size_t)ret)
			return (SUCCESS);
	}
	if (ret == -1)
	{
		free(file->content);
		perror("read");
		return (FAILURE);
	}
	return (SUCCESS);
}

int				read_file(t_file *file)
{
	int		ret;
	int		counter;

	if ((ret = fill_content(file)) == FAILURE)
		return (FAILURE);
	if (ret == ERR_MALLOC)
	{
		ft_printf(READ_MALLOC);
		return (FAILURE);
	}
	if (split_content(file) == FAILURE)
		return (FAILURE);
	counter = -1;
	while (file->lines[++counter] != NULL)
		del_comment(file->lines[counter]);
	return (SUCCESS);
}
