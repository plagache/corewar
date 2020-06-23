/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 15:35:43 by nabboufe          #+#    #+#             */
/*   Updated: 2019/01/07 16:17:00 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../includes/libft.h"

char	*ft_nstrdup(char *str, int len, int truth)
{
	int		i;
	char	*tab;

	i = 0;
	while (str[i])
		i++;
	if (i < len)
		len = i;
	i = 0;
	if (!(tab = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (str[i] && i < len)
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0';
	if (truth == 1)
		free(str);
	return (tab);
}
