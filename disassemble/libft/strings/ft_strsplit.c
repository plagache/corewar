/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 16:02:36 by nabboufe          #+#    #+#             */
/*   Updated: 2018/12/29 15:24:36 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

static int		ft_wstrlen(const char *str, const char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c)
			i++;
		while (str[i] != c && str[i])
		{
			i++;
			if (str[i] == c || str[i] == '\0')
				j++;
		}
	}
	return (j);
}

static char		**ft_allocate(int j, const char *str, const char c, char **tab)
{
	int k;
	int i;

	k = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		while (str[i] != c && str[i] != '\0')
		{
			i++;
			j++;
			if (str[i] == c || str[i] == '\0')
			{
				if (!(tab[k] = (char *)malloc(sizeof(char) * j + 1)))
					return (NULL);
				k++;
				j = 0;
			}
		}
	}
	return (tab);
}

static char		**fill_it(int i, const char *str, const char c, char **tab)
{
	int k;
	int l;

	k = 0;
	l = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		while (str[i] != c && str[i] != '\0')
		{
			tab[k][l] = str[i];
			i++;
			l++;
			if (str[i] == c || str[i] == '\0')
			{
				tab[k][l] = '\0';
				k++;
				l = 0;
			}
		}
	}
	tab[k] = 0;
	return (tab);
}

char			**ft_strsplit(const char *s, const char c)
{
	char	**tab;
	int		i;

	if (!(s))
		return (NULL);
	if (!(c))
		return (NULL);
	i = ft_wstrlen(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * i + 1)))
		return (NULL);
	if (!(tab = ft_allocate(1, s, c, tab)))
		return (NULL);
	return (fill_it(0, s, c, tab));
}
