/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_pourcentage.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 11:17:05 by danglass          #+#    #+#             */
/*   Updated: 2019/04/09 19:34:52 by nabboufe         ###   ########.fr       */
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
	if (args == NULL)
		return (0);
	while (args[a] != '\0')
	{
		if (args[a] <= '9' && args[a] > '0')
			return (ft_main_push(args, nombre, sens, zero));
		if (args[a] == '0' && sens != 'd')
			zero = '0';
		if (args[a] == 'Z' && conversion == '%')
			nombre = ft_strjoin("Z", nombre, 2);
		if (args[a] == '-')
			sens = 'd';
		if (args[a] == '.')
			return (ft_main_push(args, nombre, sens, zero));
		a++;
	}
	return (ft_main_push(args, nombre, sens, zero));
}

int				ft_conversion_pourcentage(char *args, char conversion)
{
	char	moins;
	int		retention;
	int		a;

	moins = '0';
	a = 1;
	if (conversion == '%')
		retention = ft_check_flag(args, a, ft_strdup("%", 0), conversion);
	else
		retention = ft_check_flag(args, a, ft_strdup("Z", 0), conversion);
	return (retention);
}
