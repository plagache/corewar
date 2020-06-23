/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_hexa.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 18:35:35 by damboule          #+#    #+#             */
/*   Updated: 2019/04/09 19:34:40 by nabboufe         ###   ########.fr       */
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
	{
		nombre = ft_join_int(i_largeur, zero, nombre, i_precision);
		if ((ft_whereis(args, '#', (int)ft_strlen(args) > -1) &&
			((int)ft_whereis(args, 'x', ft_strlen(args)) > -1)) &&
				args[2] == '0')
			nombre = ft_s_swap(nombre, 'x', 1);
	}
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
		if (args[a] == '0' && ft_strchar(args, '-') == -1)
			zero = '0';
		if (args[a] == '#' && conversion == 'x' && ft_strcmp(nombre, "0")
		&& ft_strlen(nombre) != 0)
			nombre = ft_strjoin("0x", nombre, 2);
		if (args[a] == '#' && conversion == 'X' && ft_strcmp(nombre, "0")
		&& ft_strlen(nombre) != 0)
			nombre = ft_strjoin("0X", nombre, 2);
		if (args[a] == '-')
			sens = 'd';
		if (args[a] == '.')
			return (ft_main_push(args, nombre, sens, zero));
		a++;
	}
	return (ft_main_push(args, nombre, sens, zero));
}

static char		ft_conversion(unsigned int num)
{
	if (num <= 9)
		return (num + '0');
	else if (num == 10)
		return ('A');
	else if (num == 11)
		return ('B');
	else if (num == 12)
		return ('C');
	else if (num == 13)
		return ('D');
	else if (num == 14)
		return ('E');
	else if (num == 15)
		return ('F');
	return (num + '0');
}

char			*ft_hexa(unsigned long long int entier, char flag)
{
	char	*result;
	int		receip;

	result = NULL;
	while (entier / 16 > 0)
	{
		receip = ft_conversion(entier % 16);
		result = ft_strjoin_free_c(result, receip);
		entier /= 16;
	}
	receip = ft_conversion(entier % 16);
	result = ft_strjoin_free_c(result, receip);
	result = ft_strrev(result);
	if (flag == 'p')
		result = ft_strjoin("0x", result, 2);
	return (result);
}

int				ft_conversion_hexa(char *args, va_list ap, char conversion)
{
	char	*nb_hexa;
	int		retention;

	nb_hexa = NULL;
	nb_hexa = ft_assign_type(nb_hexa, args, ap, conversion);
	if (conversion == 'x' || conversion == 'X')
	{
		if (conversion == 'x')
			ft_downcase(nb_hexa);
		if (nb_hexa[0] == '0' && ft_strchar(args, '.') > 0
		&& ft_strlen(nb_hexa) == 1)
			nb_hexa = ft_strndup(nb_hexa, 0, 1);
		return (retention = ft_check_flag(args, 1, nb_hexa, conversion));
	}
	else if (conversion == 'p')
	{
		ft_downcase(nb_hexa);
		ft_putstr(nb_hexa);
		if (nb_hexa != NULL)
			free(nb_hexa);
		return (ft_strlen(nb_hexa));
	}
	return (0);
}
