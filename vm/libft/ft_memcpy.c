/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:50:38 by agardina          #+#    #+#             */
/*   Updated: 2020/05/09 18:51:09 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*p_dst;
	char	*p_src;
	size_t	i;

	p_dst = (char*)dst;
	p_src = (char*)src;
	i = 0;
	while (i < n)
	{
		*(p_dst + i) = *(p_src + i);
		i++;
	}
	return (dst);
}
