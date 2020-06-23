/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 10:59:45 by nabboufe          #+#    #+#             */
/*   Updated: 2018/12/29 15:24:58 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	int		i;

	i = 0;
	if (!(s))
		return (NULL);
	if (!(tab = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (len-- > 0)
		tab[i++] = s[start++];
	tab[i] = '\0';
	return (tab);
}
