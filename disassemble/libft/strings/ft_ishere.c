/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ishere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:32:49 by nabboufe          #+#    #+#             */
/*   Updated: 2019/04/09 19:57:19 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_ishere(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (ft_strlen(needle) == 0)
		return (1);
	while (haystack[i])
	{
		while (haystack[i + j] == needle[j])
		{
			j++;
			if (needle[j] == '\0')
				return (1);
		}
		i++;
		j = 0;
	}
	return (0);
}
