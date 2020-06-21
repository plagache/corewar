/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 17:08:06 by nabboufe          #+#    #+#             */
/*   Updated: 2018/12/29 15:16:59 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*tab_dst;
	const char	*tab_src;

	tab_dst = (char *)dst;
	tab_src = (const char *)src;
	if (tab_dst > tab_src)
	{
		while (len > 0)
		{
			tab_dst[len - 1] = tab_src[len - 1];
			len--;
		}
	}
	else if (tab_dst < tab_src)
		ft_memcpy(tab_dst, tab_src, len);
	return (dst);
}
