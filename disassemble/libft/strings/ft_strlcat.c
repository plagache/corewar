/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:43:17 by nabboufe          #+#    #+#             */
/*   Updated: 2018/12/29 15:22:14 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t a;
	size_t b;
	size_t c;

	a = ft_strlen(dst);
	c = ft_strlen(src);
	i = a + c;
	if (size < a)
		i = size + c;
	b = 0;
	if (size != 0)
		size = size - 1;
	while (a < i && a < size && src[b])
	{
		dst[a] = src[b];
		a++;
		b++;
	}
	dst[a] = '\0';
	return (i);
}
