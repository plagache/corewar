/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_null.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/20 14:03:55 by damboule          #+#    #+#             */
/*   Updated: 2019/04/09 19:34:46 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_conversion_null(char *args)
{
	int		retention;
	char	conversion;

	retention = 0;
	conversion = args[ft_strlen(args) - 1];
	if (conversion == 'Z')
	{
		ft_putchar(conversion);
		retention = 1;
	}
	return (retention);
}
