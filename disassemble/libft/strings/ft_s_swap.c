/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_s_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 15:12:25 by nabboufe          #+#    #+#             */
/*   Updated: 2019/04/08 16:56:32 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_s_swap(char *s, char c, unsigned int n)
{
	int		i;
	char	tmp;

	i = 0;
	if ((ft_whereis(s, c, ft_strlen(s)) < 0))
		return (s);
	if (n > ft_strlen(s))
		return (s);
	while (s[i] != c && s[i])
		i++;
	if (s[i] == c && s[i])
	{
		tmp = s[i];
		s[i] = s[n];
		s[n] = tmp;
	}
	return (s);
}
