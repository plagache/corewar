/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_octale.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 17:30:39 by damboule          #+#    #+#             */
/*   Updated: 2019/04/09 19:34:49 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_main_push(char *args, char *nombre, char sens, char zero)
{
	int		retention;
	int		i_largeur;
	int		i_precision;

	i_largeur = ft_check_largeur(args, nombre);
	i_precision = ft_check_precision(args, nombre);
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

static int		ft_check_flag(char *args, int a, char *nombre, char conversion)
{
	char	zero;
	char	sens;

	sens = 'g';
	zero = '1';
	while (args[a] != '\0')
	{
		if (args[a] <= '9' && args[a] > '0')
			return (ft_main_push(args, nombre, sens, zero));
		if (args[a] == '0' && ft_strchar(args, '-') <= 0)
			zero = '0';
		if (args[a] == '#' && conversion == 'o' && ft_strcmp("0", nombre))
			nombre = ft_strjoin("0", nombre, 2);
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

char			*ft_octale(unsigned long long entier)
{
	char	*result;

	result = NULL;
	while (entier / 8 > 0)
	{
		result = ft_strjoin_free_c(result, (entier % 8 + '0'));
		entier /= 8;
	}
	result = ft_strjoin_free_c(result, (entier % 8 + '0'));
	result = ft_strrev(result);
	return (result);
}

int				ft_conversion_octale(char *args, va_list ap, char conversion)
{
	int		retention;
	char	*nombre;
	int		a;

	a = 1;
	nombre = NULL;
	nombre = ft_assign_type(nombre, args, ap, conversion);
	if (nombre[0] == '0' && ft_strchar(args, '.') > 0 && ft_strlen(nombre) == 1)
		nombre = ft_strndup(nombre, 0, 1);
	retention = ft_check_flag(args, a, nombre, conversion);
	return (retention);
}
