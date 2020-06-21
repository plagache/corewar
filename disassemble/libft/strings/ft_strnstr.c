/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 19:42:49 by nabboufe          #+#    #+#             */
/*   Updated: 2018/12/29 15:24:03 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t i;
	size_t i2;

	i = 0;
	i2 = 0;
	if (to_find[i2] == '\0')
		return ((char *)str);
	while (str[i] && i < n)
	{
		while (to_find[i2] == str[i + i2] && i + i2 < n)
		{
			i2++;
			if (to_find[i2] == '\0')
				return ((char *)&str[i]);
		}
		i++;
		i2 = 0;
	}
	return (0);
}
