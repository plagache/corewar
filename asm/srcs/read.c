/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 09:12:48 by plagache          #+#    #+#             */
/*   Updated: 2020/05/26 10:58:16 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "asm.h"
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
	file->lines = ft_strsplit(file->content, '\n');
	if (file->lines == NULL)
		return (FAILURE);
	return (SUCCESS);
}

static	int		fill_content(t_file *file)
{
	char buff[BUFF_SIZE + 1];
	int ret;

	file->content = ft_strnew(0);
	if (file->content == NULL)
		return (FAILURE);
	while ((ret = read(file->fd, buff, BUFF_SIZE)) > 0)
	{
		buff[ret] = '\0';
		file->content = ft_strjoinfree(1, file->content, buff);
		if (file->content == NULL)
			return (FAILURE);
		if (ft_strlen(buff) != ret)
			return (SUCCESS);
	}
	if (ret == -1)
	{
		free(file->content);
		ft_printf(ERROR_OPEN, file->name);
		return (FAILURE);
	}
	return (SUCCESS);
}

int				read_file(t_file *file)
{
	int		counter;

	if (fill_content(file) == FAILURE)
		return (FAILURE);
	if (split_content(file) == FAILURE)
		return (FAILURE);
	counter = 0;
	while (file->lines[counter] != NULL)
	{
		del_comment(file->lines[counter]);
		counter++;
	}
	return (SUCCESS);
}