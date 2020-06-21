/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:59:41 by nabboufe          #+#    #+#             */
/*   Updated: 2018/12/29 15:16:13 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*tab_dst;
	unsigned const char	*tab_src;

	tab_dst = (unsigned char *)dst;
	tab_src = (unsigned const char *)src;
	while (n > 0)
	{
		*tab_dst = *tab_src;
		if ((*tab_dst++ = *tab_src++) == (unsigned char)c)
			return (tab_dst);
		n--;
	}
	return (NULL);
}
