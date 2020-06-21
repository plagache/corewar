/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 17:58:31 by nabboufe          #+#    #+#             */
/*   Updated: 2019/04/08 17:03:25 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

char	*ft_strjoin(char *s1, char *s2, unsigned int truth)
{
	char	*tab;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!(s1) || !(s2))
		return (NULL);
	if (!(tab = (char *)malloc(sizeof(char) * ft_strlen(s1) +
					ft_strlen(s2) + 1)))
		return (NULL);
	while (s1[i])
		tab[j++] = s1[i++];
	i = 0;
	while (s2[i])
		tab[j++] = s2[i++];
	tab[j] = '\0';
	if (truth == 1 || truth == 3)
		if (s1)
			free(s1);
	if (truth == 2 || truth == 3)
		if (s2)
			free(s2);
	return (tab);
}
