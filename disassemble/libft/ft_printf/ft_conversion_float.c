/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_float.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 15:58:23 by danglass          #+#    #+#             */
/*   Updated: 2019/04/09 19:34:37 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void			ft_decimal(char *nombre, int precision)
{
	int		i;

	i = 0;
	while (nombre[i] != '.' && nombre[i])
		i++;
	if (precision > 0)
		i++;
	while (nombre[i] && precision-- > 0)
		i++;
	while (nombre[i])
	{
		nombre[i] = '\0';
		i++;
	}
}

static int		ft_main_push(char *args, char *nombre, char sens, char zero)
{
	int		retention;
	int		i_largeur;
	int		i_precision;

	i_largeur = ft_check_largeur(args, nombre);
	i_precision = ft_check_precision(args, nombre);
	if (i_precision != -1)
		ft_decimal(nombre, i_precision);
	i_precision = i_precision - ft_count_num(nombre);
	if (i_precision <= 0)
		i_precision = -1;
	if (sens == 'g')
		nombre = ft_join_int(i_largeur, zero, nombre, i_precision);
	else
		nombre = ft_join_r_int(i_largeur, zero, nombre, i_precision);
	ft_putstr(nombre);
	retention = ft_strlen(nombre);
	if (nombre)
		free(nombre);
	return (retention);
}

static int		ft_check_flag(char *args, int a, char *nombre)
{
	char	zero;
	char	sens;

	sens = 'g';
	zero = '1';
	while (args[a] != '\0')
	{
		if (args[a] <= '9' && args[a] > '0')
			return (ft_main_push(args, nombre, sens, zero));
		if (args[a] == '0')
			zero = '0';
		if (args[a] == ' ')
			nombre = ft_check_signe(args, nombre);
		if (args[a] == '-')
			sens = 'd';
		if (args[a] == '.')
			return (ft_main_push(args, nombre, sens, zero));
		a++;
	}
	return (ft_main_push(args, nombre, sens, zero));
}

int				ft_conversion_float(char *args, va_list ap, char conversion)
{
	double	entier;
	char	*nb;
	int		a;
	int		retention;

	a = 1;
	nb = NULL;
	retention = 0;
	if (conversion == 'f')
	{
		entier = va_arg(ap, double);
		nb = ft_float(entier, 7);
		retention = ft_check_flag(args, a, nb);
	}
	return (retention);
}
