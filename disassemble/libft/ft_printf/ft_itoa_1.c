/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:27:34 by damboule          #+#    #+#             */
/*   Updated: 2019/04/09 19:49:16 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_taille_long_long(unsigned long long n)
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

char		*ft_itoa_unsigned_long_long(unsigned long long n)
{
	char	*tab;
	int		len;

	len = ft_taille_long_long(n);
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

static int	ft_taille_l_l(long long int n)
{
	int		len;

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

char		*ft_itoa_long_long(long long int n)
{
	char			*tab;
	unsigned long	le;
	int				neg;
	int				len;

	le = (unsigned long)n;
	if (le == -9223372036854775808u)
		return (ft_strdup("-9223372036854775808", 0));
	neg = 0;
	if (n < 0)
		neg = -1;
	len = ft_taille_l_l(n);
	tab = (char*)malloc(sizeof(char) * len + 1);
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

char		*ft_itoa_long(long int n)
{
	char	*tab;
	int		neg;
	int		len;

	neg = 0;
	if (n < 0)
		neg = -1;
	len = ft_taille_l_l(n);
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
