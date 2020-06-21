/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 13:10:23 by damboule          #+#    #+#             */
/*   Updated: 2019/04/09 21:17:32 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_check_flag(char *args, va_list ap, char conversion)
{
	if (conversion == 'c' || conversion == 's')
		return (ft_conversion_char(args, ap, conversion));
	if (conversion == 'd' || conversion == 'i' || conversion == 'u')
		return (ft_conversion_int(args, ap, conversion));
	if (conversion == 'p' || conversion == 'x' || conversion == 'X')
		return (ft_conversion_hexa(args, ap, conversion));
	if (conversion == 'o')
		return (ft_conversion_octale(args, ap, conversion));
	if (conversion == 'f')
		return (ft_conversion_float(args, ap, conversion));
	if (conversion == '%' || conversion == 'Z')
		return (ft_conversion_pourcentage(args, conversion));
	if (conversion == '\0')
		return (ft_conversion_null(args));
	return (0);
}

int		ft_find(char *string, int index)
{
	if (index == 0)
		return (1);
	if (string[index] == '%' || string[index] == 'Z')
		return (0);
	if (string[index] == 'p' || string[index] == 'x' || string[index] == 'X')
		return (0);
	if (string[index] == 'd' || string[index] == 'i' || string[index] == 'u')
		return (0);
	if (string[index] == 'c' || string[index] == 's')
		return (0);
	if (string[index] == 'o' || string[index] == 'f')
		return (0);
	return (1);
}

int		ft_args_parse(char *string, va_list ap, int *a)
{
	int		index;
	char	*args;
	int		i;

	index = 0;
	while (string[index] && (i = ft_find(string, index)))
		index++;
	if (string[index] == '\0' && index == 1)
		return (0);
	args = ft_strndup(string, index + 1, 0);
	*a += index;
	index = ft_check_flag(args, ap, string[index]);
	if (args)
		free(args);
	return (index);
}

int		ft_parse(const char *format, va_list ap, int ret)
{
	int		a;
	char	*str;

	a = 0;
	str = (char *)format;
	if (str == NULL || str[a] == '\0')
		return (0);
	while (str[a] != '\0' && ((a == 0) || str[a - 1] != '\0'))
	{
		if (str[a] != '%' && str[a])
			ret += write(1, &str[a], 1);
		else if (str[a] == '%')
			ret += ft_args_parse(&str[a], ap, &a);
		a++;
	}
	return (ret);
}

int		ft_printf(const char *format, ...)
{
	int		retention;
	char	*buffer;
	va_list	ap;
	int		i;

	i = 0;
	retention = 0;
	buffer = NULL;
	va_start(ap, format);
	retention = ft_parse(format, ap, retention);
	va_end(ap);
	return (retention);
}
