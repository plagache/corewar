/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool_conversion.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 15:47:36 by damboule          #+#    #+#             */
/*   Updated: 2019/04/09 19:35:12 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_join_r_int(int largeur, char zero, char *numero, int precision)
{
	int		len;

	len = -1;
	if ((precision > 0 || largeur > 0) && (zero == '0' || precision > 0))
	{
		while (++len < largeur || len < precision)
		{
			if (len < precision)
				numero = ft_strjoin("0", numero, 2);
			else if (len >= precision)
				numero = ft_strjoin(numero, "0", 1);
			if (len + 1 >= precision)
			{
				while (++len < largeur && zero == '1')
					numero = ft_strjoin(numero, " ", 1);
			}
		}
		return (numero);
	}
	if (largeur > 0 || precision > 0)
		while (++len < largeur)
			numero = ft_strjoin(numero, " ", 1);
	return (numero);
}

int		ft_check_largeur(char *args, char *numero)
{
	int		a;
	int		nb;
	char	*largeur;
	int		i_largeur;

	largeur = NULL;
	a = 0;
	while (args[a] && (!(args[a] <= '9' && args[a] > '0')))
		a++;
	if (args[a - 1] == '.' || args[a] == '\0')
		return (0);
	while (args[a] && (args[a] <= '9' && args[a] >= '0'))
	{
		largeur = ft_strjoin_free_c(largeur, args[a]);
		a++;
	}
	nb = ft_atoi(largeur);
	if (largeur)
		free(largeur);
	i_largeur = nb - ft_strlen(numero);
	return (i_largeur);
}

int		ft_check_precision(char *args, char *numero)
{
	int		index;
	int		nb;
	int		i_precision;
	char	*precision;

	nb = 0;
	if ((index = ft_strchar(args, '.')) == -1)
		return (-1);
	index = index + 1;
	precision = NULL;
	while (args[index] && (args[index] <= '9' && args[index] >= '0'))
	{
		precision = ft_strjoin_free_c(precision, args[index]);
		index++;
	}
	if (precision != NULL)
	{
		nb = ft_atoi(precision);
		free(precision);
	}
	ft_strchar(args, 'f') == -1 ? (i_precision = nb - ft_count_num(numero)) :
		(i_precision = nb);
	if ((ft_strchar(args, 'f') == -1) && i_precision <= 0)
		return (-1);
	return (i_precision);
}

char	*ft_check_signe(char *args, char *nb_hexa)
{
	int		pos;
	int		nb;
	char	*tmp;

	pos = ft_chrlen(args, '+');
	if (pos > 1)
	{
		nb = ft_atoi(nb_hexa) * -1;
		tmp = nb_hexa;
		nb_hexa = ft_itoa(nb);
		if (tmp)
			free(tmp);
	}
	if (ft_chrlen(args, '+') && ft_atoi(nb_hexa) >= 0
	&& ft_strchar(nb_hexa, '+'))
		return (nb_hexa = ft_strjoin("+", nb_hexa, 2));
	return (nb_hexa);
}
