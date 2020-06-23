/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:12:46 by nabboufe          #+#    #+#             */
/*   Updated: 2018/12/29 15:16:05 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

void	*ft_memalloc(size_t size)
{
	char *t;

	if (!(t = (malloc(size * 1))))
		return (NULL);
	if (!(ft_bzero((void *)t, size)))
		return (NULL);
	return ((void *)t);
}
