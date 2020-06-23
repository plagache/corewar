/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 15:34:49 by damboule          #+#    #+#             */
/*   Updated: 2019/04/16 15:03:22 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int				ft_print(char *nombre)
{
	int		ret;
	int		i;

	i = 0;
	ret = 0;
	if (ft_strlen(nombre) == 2)
		ret = write(1, "", 1);
	else
	{
		while (nombre[i] == ' ')
			i++;
		while (i-- > 0)
			ret += write(1, " ", 1);
		ret += write(1, "", 1);
	}
	if (nombre)
		free(nombre);
	return (ret);
}

static int		ft_main_push(char *args, char *nombre, char sens, char zero)
{
	int		retention;
	int		i_largeur;
	int		i_precision;

	i_largeur = ft_check_largeur_char(args);
	i_precision = ft_check_precision_char(args);
	if (i_precision != -1)
		nombre = ft_strndup(nombre, i_precision, 1);
	if (sens == 'g')
		nombre = ft_join_char(i_largeur, zero, nombre);
	else
		nombre = ft_join_reverse_char(i_largeur, zero, nombre);
	if (ft_ishere(nombre, "^@") == 1)
		return (ft_print(nombre));
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
		if (args[a] == '0' && zero != -1)
			zero = '0';
		if (args[a] == ' ')
			nombre = ft_check_signe(args, nombre);
		if (args[a] == '-')
		{
			sens = 'd';
			zero = -1;
		}
		if (args[a] == '.')
			return (ft_main_push(args, nombre, sens, zero));
		a++;
	}
	return (ft_main_push(args, nombre, sens, zero));
}

int				ft_conversion_char(char *args, va_list ap, char conversion)
{
	char	*string;
	int		caract;
	int		retention;

	string = NULL;
	retention = 0;
	if (conversion == 's')
	{
		string = ft_strdup((char*)(va_arg(ap, char *)), 0);
		if (string == NULL)
			string = ft_strjoin("", "(null)", 0);
		retention = ft_check_flag(args, 1, string);
	}
	else if (conversion == 'c')
	{
		caract = va_arg(ap, int);
		string = ft_strjoin_free_c(string, caract);
		if (caract == 0)
			string = ft_strjoin(string, "^@", 1);
		retention = ft_check_flag(args, 1, string);
	}
	return (retention);
}
