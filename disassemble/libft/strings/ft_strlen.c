/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:07:03 by nabboufe          #+#    #+#             */
/*   Updated: 2018/12/29 18:18:02 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

size_t		ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		if (!(s[i + 1]))
			return (i + 1);
		if (!(s[i + 2]))
			return (i + 2);
		if (!(s[i + 3]))
			return (i + 3);
		if (!(s[i + 4]))
			return (i + 4);
		i = i + 4;
	}
	return (i);
}
