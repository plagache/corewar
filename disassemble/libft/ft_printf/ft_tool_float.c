/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool_float.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:13:25 by damboule          #+#    #+#             */
/*   Updated: 2019/04/09 19:35:15 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_put_arrondie(int count, int a, char *nombre)
{
	int point;

	point = ft_strchar(nombre, '.');
	if (count < 6 && (a - count) <= point)
		return (nombre);
	while (count > 0 && nombre[a] != '.')
	{
		nombre[a] = '0';
		a--;
		count--;
	}
	if (nombre[a] == '.')
		a = a - 1;
	nombre[a] = nombre[a] + 1;
	return (nombre);
}

char		*ft_arrondie(char *nombre)
{
	int	count;
	int	a;
	int	ret;

	a = ft_strlen(nombre);
	while (a > 0)
	{
		count = 0;
		ret = a;
		while (nombre[ret] == '9')
		{
			count++;
			ret--;
		}
		if (count >= 2)
		{
			nombre = ft_put_arrondie(count, a, nombre);
			a = a - count;
		}
		a--;
	}
	nombre[ft_strlen(nombre) - 1] = '\0';
	return (nombre);
}

char		*ft_float(double f, int decimale)
{
	char	*nombre;
	int		nb;

	nombre = NULL;
	nb = f;
	f = f - nb;
	if (f < 0 && nb == 0)
		nombre = ft_strdup("-0", 0);
	else
		nombre = ft_strjoin(ft_itoa(nb), nombre, 1);
	nombre = ft_strjoin_free_c(nombre, '.');
	if (f < 0)
		f = (f * -1);
	while (decimale > 0)
	{
		f = f * 10;
		nb = f;
		f = f - nb;
		nombre = ft_strjoin_free_c(nombre, nb + '0');
		decimale--;
	}
	nombre = ft_arrondie(nombre);
	return (nombre);
}

int			ft_count_moins(char *nombre)
{
	int a;

	a = 0;
	if (ft_strchar(nombre, '-') <= 0 && ft_strchar(nombre, '+') <= 0)
		return (1);
	while (nombre[a])
	{
		if ((nombre[a] == '-' || nombre[a] == '+')
		&& (nombre[a + 1] <= '9' && nombre[a + 1] >= '0')
		&& (nombre[a - 1] > '9' || nombre[a - 1] < '0'))
			return (1);
		a++;
	}
	return (0);
}

char		*ft_putmoins(char *nombre)
{
	int		a;
	int		b;
	char	*buffer;

	a = 0;
	b = 0;
	if (ft_count_moins(nombre))
		return (nombre);
	buffer = ft_strnew(ft_strlen(nombre));
	while (nombre[a] != '\0')
	{
		if (nombre[a] != '-' && nombre[a] != '+')
		{
			buffer[b] = nombre[a];
			b++;
		}
		a++;
	}
	if (ft_chrlen(nombre, '-') > 0)
		return (ft_moins(buffer));
	return (ft_plus(buffer));
}
