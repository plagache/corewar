/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool_cast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 17:02:18 by damboule          #+#    #+#             */
/*   Updated: 2019/04/09 19:35:07 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_unsigned_long(char *nombre, va_list ap, char conversion)
{
	unsigned long		i_value;

	if (nombre)
		free(nombre);
	i_value = va_arg(ap, unsigned long);
	if (conversion == 'x' || conversion == 'X')
		return (ft_hexa(i_value, conversion));
	if (conversion == 'o')
		return (ft_octale(i_value));
	nombre = ft_itoa_unsigned_long(i_value);
	return (nombre);
}

char	*ft_unsigned_long_long(char *nombre, va_list ap, char conversion)
{
	unsigned long long	i_value;

	i_value = va_arg(ap, unsigned long long);
	if (nombre)
		free(nombre);
	if (conversion == 'x' || conversion == 'X')
		return (ft_hexa(i_value, conversion));
	if (conversion == 'o')
		return (ft_octale(i_value));
	if (conversion == 'p')
		return (ft_hexa(i_value, conversion));
	nombre = ft_itoa_unsigned_long_long(i_value);
	return (nombre);
}

char	*ft_unsigned_h(char *nombre, va_list ap, char conversion)
{
	unsigned short		i_value;

	i_value = (unsigned short)va_arg(ap, int);
	if (nombre)
		free(nombre);
	if (conversion == 'x' || conversion == 'X')
		return (ft_hexa(i_value, conversion));
	if (conversion == 'o')
		return (ft_octale(i_value));
	nombre = ft_itoa_unsigned_long(i_value);
	return (nombre);
}

char	*ft_unsigned_h_h(char *nombre, va_list ap, char conversion)
{
	short	i_value;

	i_value = (unsigned char)va_arg(ap, unsigned int);
	if (nombre)
		free(nombre);
	if (conversion == 'x' || conversion == 'X')
		return (ft_hexa(i_value, conversion));
	if (conversion == 'o')
		return (ft_octale(i_value));
	nombre = ft_itoa_unsigned_long_long(i_value);
	return (nombre);
}
