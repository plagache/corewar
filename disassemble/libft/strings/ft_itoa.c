/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:38:16 by damboule          #+#    #+#             */
/*   Updated: 2019/04/09 19:56:57 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

static int	ft_taille(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len += 1;
	}
	while (n / 10 > 0)
	{
		len++;
		n /= 10;
	}
	return (len + 1);
}

char		*ft_itoa(int n)
{
	char	*tab;
	int		neg;
	int		len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648", 0));
	neg = 0;
	if (n < 0)
		neg = -1;
	len = ft_taille(n);
	tab = (char*)malloc(sizeof(char) * len + 1);
	if (tab == NULL)
		return (NULL);
	if (n < 0)
		n *= -1;
	tab[len] = '\0';
	while (len--)
	{
		tab[len] = (n % 10) + '0';
		n /= 10;
	}
	if (neg == -1)
		tab[0] = '-';
	return (tab);
}
