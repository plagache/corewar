/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:51:57 by nabboufe          #+#    #+#             */
/*   Updated: 2018/12/29 15:24:14 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	d;

	i = 0;
	d = (char)c;
	if (d == '\0')
	{
		while (s[i])
			i++;
		return ((char *)&s[i]);
	}
	while (s[i])
		i++;
	while (i > 0)
	{
		i--;
		if (s[i] == d)
			return ((char *)&s[i]);
	}
	return (NULL);
}
