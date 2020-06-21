/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 12:41:46 by nabboufe          #+#    #+#             */
/*   Updated: 2019/04/09 19:55:34 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_count_num(char *numero)
{
	int len;

	len = ft_strlen(numero);
	if (ft_strchar(numero, '-') >= 0 || ft_strchar(numero, '+') >= 0)
		len = len - 1;
	return (len);
}
