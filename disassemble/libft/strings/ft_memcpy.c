/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 16:08:32 by nabboufe          #+#    #+#             */
/*   Updated: 2018/12/29 15:16:40 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*tab;
	const char	*tab2;

	tab = (char *)dst;
	tab2 = (const char *)src;
	while (n > 0)
	{
		*tab = *tab2;
		tab++;
		tab2++;
		n--;
	}
	return (dst);
}
