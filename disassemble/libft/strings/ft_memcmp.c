/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:14:58 by nabboufe          #+#    #+#             */
/*   Updated: 2018/12/29 15:16:30 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const char	*tab_s1;
	const char	*tab_s2;
	size_t		i;

	i = 0;
	tab_s1 = (const char *)s1;
	tab_s2 = (const char *)s2;
	if (s1 == s2)
		return (0);
	while (n > i)
	{
		if (tab_s1[i] != tab_s2[i])
			return ((unsigned char)tab_s1[i] - (unsigned char)tab_s2[i]);
		i++;
	}
	return (0);
}
