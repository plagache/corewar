/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 12:41:46 by nabboufe          #+#    #+#             */
/*   Updated: 2019/04/08 16:17:57 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int		ft_count_num(char *numero)
{
	int len;

	len = ft_strlen(numero);
	if (ft_strchar(numero, '-') >= 0 || ft_strchar(numero, '+') >= 0)
		len = len - 1;
	return (len);
}
