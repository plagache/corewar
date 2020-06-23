/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 22:13:14 by nabboufe          #+#    #+#             */
/*   Updated: 2018/12/29 15:23:52 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char *tab;

	if (!(tab = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	if (!(ft_bzero((void *)tab, size + 1)))
		return (NULL);
	return (tab);
}
