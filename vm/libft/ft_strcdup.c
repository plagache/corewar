/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 10:46:53 by agardina          #+#    #+#             */
/*   Updated: 2019/09/19 11:08:47 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

/*
** This function returns a copy of the string str until the char c included
** (if incl_c is different from 0) or excluded (if incl_c equals 0).
** If c is not in str, NULL is returned if copy_all equals 0, otherwise
** a copy of str is returned.
*/

char	*ft_strcdup(const char *str, char c, int incl_c, int copy_all)
{
	int		len;
	char	*new;
	int		i;
	char	*end;

	end = ft_strchr(str, c);
	if (!str || (!end && !copy_all))
		return (NULL);
	if ((!end && copy_all) || !c)
		len = ft_strlen(str);
	else
		len = end - str - (incl_c == 1 ? 0 : 1) + 1;
	if (!(new = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		new[i] = str[i];
		i++;
	}
	new[len] = '\0';
	return (new);
}
