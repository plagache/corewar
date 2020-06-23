/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 16:16:10 by nabboufe          #+#    #+#             */
/*   Updated: 2018/12/29 15:25:17 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

static int		ft_wstrlen(const char *s)
{
	int i;
	int j;
	int k;

	j = 0;
	k = 0;
	while (s[k] == 32 || s[k] == '\t' || s[k] == '\n')
		k++;
	i = k;
	while (s[i] != 32 && s[i] != '\t' && s[i] != '\n' && s[i] != '\0')
	{
		i++;
		while (s[i + j] == 32 || s[i + j] == '\t' || s[i + j] == '\n')
		{
			j++;
			if (s[i + j] != 32 && s[i + j] != '\t' && s[i + j] != '\n' &&
					s[i + j] != '\0')
			{
				i = i + j;
				j = 0;
			}
		}
	}
	return (i - k);
}

static char		*ft_fill(const char *s, char *tab)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (s[i] == 32 || s[i] == '\t' || s[i] == '\n')
		i++;
	j = i;
	while (i < ft_wstrlen(s) + j)
		tab[k++] = s[i++];
	tab[k] = '\0';
	return (tab);
}

char			*ft_strtrim(char const *s)
{
	char *tab;

	if (!(s))
		return (NULL);
	if (!(tab = (char *)malloc(sizeof(char) * ft_wstrlen(s) + 1)))
		return (NULL);
	if (!(tab = ft_fill(s, tab)))
		return (NULL);
	return (tab);
}
