/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:31:28 by damboule          #+#    #+#             */
/*   Updated: 2019/04/09 19:34:59 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int			ft_atoi_unsigned(const char *str)
{
	int				i;
	unsigned int	nb;

	i = 0;
	nb = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + str[i] - '0';
		i++;
	}
	return (nb);
}

static int	ft_taille(unsigned int n)
{
	int		len;

	len = 0;
	while (n / 10 > 0)
	{
		len++;
		n /= 10;
	}
	return (len + 1);
}

char		*ft_itoa_unsigned(unsigned int n)
{
	char	*tab;
	int		len;

	len = ft_taille(n);
	tab = (char*)malloc(sizeof(char ) * len + 1);
	if (tab == NULL)
		return (NULL);
	tab[len] = '\0';
	while (len--)
	{
		tab[len] = (n % 10) + '0';
		n /= 10;
	}
	return (tab);
}

static int	ft_taille_long(unsigned long n)
{
	int		len;

	len = 0;
	while (n / 10 > 0)
	{
		len++;
		n /= 10;
	}
	return (len + 1);
}

char		*ft_itoa_unsigned_long(unsigned long n)
{
	char	*tab;
	int		len;

	len = ft_taille_long(n);
	tab = (char*)malloc(sizeof(char ) * len + 1);
	if (tab == NULL)
		return (NULL);
	tab[len] = '\0';
	while (len--)
	{
		tab[len] = (n % 10) + '0';
		n /= 10;
	}
	return (tab);
}
