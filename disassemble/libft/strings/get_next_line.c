/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 14:56:00 by nabboufe          #+#    #+#             */
/*   Updated: 2019/01/05 12:05:53 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"
#include <fcntl.h>

static char		*read_it(char **tab, char *buff, const int fd)
{
	unsigned int	i;

	i = 1;
	while (!(ft_strchr(*tab, '\n')) && i)
	{
		i = read(fd, buff, BUFF_SIZE);
		if (i)
		{
			buff[i] = '\0';
			if (!(*tab = ft_strjoin(*tab, buff, 1)))
				return (NULL);
		}
	}
	free(buff);
	return (*tab);
}

static char		*return_line(char **tab)
{
	char	*buff;
	char	*nline;
	char	*tmp;

	buff = ft_strchr(*tab, '\n');
	tmp = NULL;
	if (buff)
	{
		tmp = *tab;
		if (!(nline = ft_nstrdup(*tab, buff - *tab, 0)))
			return (NULL);
		if (!(*tab = ft_strdup(buff + 1, 0)))
			return (NULL);
		free(tmp);
	}
	else if (!(nline = ft_strdup(*tab, 0)))
		return (NULL);
	if (!(*tab) || !(tmp))
	{
		free(*tab);
		*tab = NULL;
	}
	return (nline);
}

int				get_next_line(const int fd, char **line)
{
	static char		*tab = NULL;
	char			*buff;

	buff = NULL;
	if (fd < 0 || !line || BUFF_SIZE < 1 || !(buff = ft_strnew(BUFF_SIZE
			+ 1)) || (tab == NULL && !(tab = ft_strnew(0))))
		return (-1);
	if (read(fd, buff, 0) == -1 || !(read_it(&tab, buff, fd)))
		return (-1);
	if (*tab)
	{
		if (!(*line = return_line(&tab)))
			return (-1);
		return (1);
	}
	return (0);
}
