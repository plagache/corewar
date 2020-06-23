/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 10:44:41 by danglass          #+#    #+#             */
/*   Updated: 2019/04/09 19:35:19 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_join_int(int largeur, char zero, char *numero, int precision)
{
	int	len;

	len = -1;
	if (largeur > 0 || precision > 0)
	{
		if (zero == '0' || precision > 0)
		{
			while (++len < largeur || len < precision)
			{
				numero = ft_strjoin("0", numero, 2);
				if (len + 1 >= precision && precision != -1)
				{
					while (++len < largeur)
						numero = ft_strjoin(" ", numero, 2);
				}
			}
			return (ft_strndup(numero, ft_strlen(numero), 1));
		}
		while (++len < largeur)
			numero = ft_strjoin(" ", numero, 2);
		return (ft_strndup(numero, ft_strlen(numero), 1));
	}
	return (numero);
}

char	*ft_unsigned(char *nombre, va_list ap, char conversion)
{
	unsigned int	i_value;

	i_value = va_arg(ap, unsigned int);
	if (nombre)
		free(nombre);
	if (conversion == 'x' || conversion == 'X')
		return (ft_hexa(i_value, conversion));
	else if (conversion == 'o')
		return (ft_octale(i_value));
	nombre = ft_itoa_unsigned(i_value);
	return (nombre);
}

char	*ft_int(char *nombre, va_list ap)
{
	int i_value;

	i_value = va_arg(ap, int);
	nombre = ft_itoa(i_value);
	return (nombre);
}

char	*ft_long_long(char *nombre, va_list ap)
{
	long long	i_value;

	i_value = va_arg(ap, long long);
	nombre = ft_itoa_long_long(i_value);
	return (nombre);
}

char	*ft_long(char *nombre, va_list ap)
{
	long	i_value;

	i_value = va_arg(ap, long);
	nombre = ft_itoa_long(i_value);
	return (nombre);
}
