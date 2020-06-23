/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 21:29:22 by nabboufe          #+#    #+#             */
/*   Updated: 2018/12/29 15:17:10 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*tab;

	tab = (unsigned char *)b;
	while (len > 0)
	{
		*tab = (unsigned char)c;
		tab++;
		len--;
	}
	return (b);
}
