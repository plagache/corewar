/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 11:50:05 by nabboufe          #+#    #+#             */
/*   Updated: 2018/12/29 15:23:32 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (1);
	if (!(s1) || !(s2))
		return (0);
	if (s1[i] == '\0' && s2[i] == '\0')
		return (1);
	while (s1[i] == s2[i] && s1[i] && i < n)
	{
		i++;
		if (i == n || (s1[i] == '\0' && s1[i] == s2[i]))
			return (1);
	}
	return (0);
}
