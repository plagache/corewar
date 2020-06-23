/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 19:38:53 by danglass          #+#    #+#             */
/*   Updated: 2019/04/09 19:34:55 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char		*ft_repartition(char conversion, va_list ap, char *nombre)
{
	if (conversion == 'd' || conversion == 'i')
		return (nombre = ft_int(nombre, ap));
	else if (conversion == 'u' || conversion == 'x'
			|| conversion == 'X' || conversion == 'o')
		return (nombre = ft_unsigned(nombre, ap, conversion));
	else if (conversion == 'p')
		return (nombre = ft_unsigned_long_long(nombre, ap, conversion));
	return (nombre);
}

char		*ft_signed_char(char *nombre, va_list ap)
{
	signed char i_value;

	i_value = (signed char)va_arg(ap, int);
	nombre = ft_itoa(i_value);
	return (nombre);
}

char		*ft_ll(char *n, char *f, va_list a, char c)
{
	if (f[0] == 'l' && f[1] == 'l' && (c == 'u' || c == 'x' || c == 'X'
			|| c == 'o'))
		return (ft_unsigned_long_long(n, a, c));
	if (f[0] == 'l' && f[1] != 'l' && (c == 'u'
			|| c == 'x' || c == 'X' || c == 'o'))
		return (ft_unsigned_long(n, a, c));
	if (f[0] == 'l' && f[1] == 'l' && (c == 'd' || c == 'i'))
		return (ft_long_long(n, a));
	if (f[0] == 'l' && f[1] != 'l' && (c == 'd' || c == 'i'))
		return (ft_long(n, a));
	return (NULL);
}

char		*ft_hh(char *n, char *f, va_list a, char c)
{
	if (f[0] == 'h' && f[1] == 'h' && (c == 'd' || c == 'i'))
		return (ft_signed_char(n, a));
	if (f[0] == 'h' && f[1] == 'h' && (c == 'u'
			|| c == 'x' || c == 'X' || c == 'o'))
		return (ft_unsigned_h_h(n, a, c));
	if (f[0] == 'h' && f[1] != 'h' && (c == 'u'
			|| c == 'x' || c == 'X' || c == 'o'))
		return (ft_unsigned_h(n, a, c));
	if (f[0] == 'h' && (c == 'd' || c == 'i'))
		return (ft_short(n, a));
	return (NULL);
}

char		*ft_assign_type(char *n, char *f, va_list a, char c)
{
	int		i;
	char	*tmp;

	tmp = NULL;
	i = -1;
	while (f[++i])
	{
		if (f[i] == 'l' && (c == 'd' || c == 'i' || c == 'o'
					|| c == 'u' || c == 'x' || c == 'X'))
			return ((tmp = ft_ll(n, &f[i], a, c)));
		if (f[i] == 'h' && (c == 'd' || c == 'i' || c == 'o'
					|| c == 'u' || c == 'x' || c == 'X'))
			return ((tmp = ft_hh(n, &f[i], a, c)));
	}
	return (ft_repartition(c, a, n));
}
