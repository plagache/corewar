/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_int.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 19:31:57 by damboule          #+#    #+#             */
/*   Updated: 2019/04/09 19:34:43 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char			*ft_plus(char *tab)
{
	int		a;
	int		b;
	int		count;
	char	*buffer;

	a = 0;
	b = 0;
	count = 0;
	if (tab[a] <= '9' && tab[a] >= '0')
		return (ft_strjoin("+", tab, 2));
	buffer = ft_strnew(ft_strlen(tab) + 2);
	while (tab[a])
	{
		if (count == 0 && tab[a] <= '9' && tab[a] >= '0')
		{
			buffer[b] = '+';
			b++;
			count++;
		}
		buffer[b] = tab[a];
		b++;
		a++;
	}
	return (buffer);
}

char			*ft_moins(char *tab)
{
	int		a;
	int		b;
	char	*buffer;

	a = 0;
	b = 0;
	if (tab[a] <= '9' && tab[a] >= '0')
		return (ft_strjoin("-", tab, 2));
	buffer = ft_strnew(ft_strlen(tab) + 2);
	while (tab[a])
	{
		if (tab[a + 1] <= '9' && tab[a + 1] >= '0')
		{
			buffer[b] = '-';
			b++;
		}
		buffer[b++] = tab[a++];
	}
	return (buffer);
}

static int		ft_main_push(char *args, char *nombre, char sens, char zero)
{
	int	retention;
	int	i_largeur;
	int	i_precision;

	i_largeur = ft_check_largeur(args, nombre);
	i_precision = ft_check_precision(args, nombre);
	if (sens == 'g')
		nombre = ft_join_int(i_largeur, zero, nombre, i_precision);
	else
		nombre = ft_join_r_int(i_largeur, zero, nombre, i_precision);
	nombre = ft_putmoins(nombre);
	ft_putstr(nombre);
	retention = ft_strlen(nombre);
	if (nombre)
		free(nombre);
	return (retention);
}

static int		ft_check_flag(char *a, int b, char *n)
{
	char	zero;
	char	sens;

	sens = 'g';
	zero = '1';
	while (a[b] != '\0')
	{
		if (a[b] == '+')
			n = ft_check_signe(a, n);
		if (a[b] <= '9' && a[b] > '0')
			return (ft_main_push(a, n, sens, zero));
		if (a[b] == '0' && ft_strchar(a, '-') <= 0)
			zero = '0';
		if (a[b] == ' ' && ft_strchar(a, '+') <= 0
		&& n[0] != '-' && ft_strchar(a, '.') <= 0 && a[ft_strlen(a) - 1] != 'u')
			n = ft_strjoin(" ", n, 2);
		if (a[b] == '-')
			sens = 'd';
		if (a[b++] == '.')
			return (ft_main_push(a, n, sens, zero));
	}
	return (ft_main_push(a, n, sens, zero));
}

int				ft_conversion_int(char *args, va_list ap, char conversion)
{
	int		retention;
	char	*nombre;
	int		a;

	a = 1;
	retention = 0;
	nombre = NULL;
	if (conversion == 'd' || conversion == 'i')
	{
		nombre = ft_assign_type(nombre, args, ap, conversion);
		if (nombre[0] == '0' && ft_strchar(args, '.') > 0)
			nombre = ft_strndup(nombre, 0, 1);
		retention = ft_check_flag(args, a, nombre);
	}
	else if (conversion == 'u')
	{
		nombre = ft_assign_type(nombre, args, ap, conversion);
		retention = ft_check_flag(args, a, nombre);
	}
	return (retention);
}
