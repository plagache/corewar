/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 16:31:09 by damboule          #+#    #+#             */
/*   Updated: 2019/04/09 19:55:58 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdio.h>

int		ft_strchar(char *str, char occurency)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != occurency)
	{
		i++;
		if (str[i] == occurency)
			return (i);
	}
	if (str[i] == occurency)
		return (i);
	return (-1);
}
