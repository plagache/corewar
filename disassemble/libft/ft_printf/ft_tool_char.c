/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 09:55:57 by danglass          #+#    #+#             */
/*   Updated: 2019/04/16 15:03:44 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_taille(char *string)
{
	int len;
	int	count;
	int	a;

	len = ft_strlen(string);
	a = 0;
	count = 0;
	while (string[a])
	{
		if (string[a] == '^' && string[a + 1] == '@')
		{
			count = 1;
			return (len - count);
		}
		a++;
	}
	return (len);
}

char	*ft_join_reverse_char(int largeur, char zero, char *string)
{
	int	len;
	int taille;

	len = 0;
	taille = ft_taille(string);
	largeur = largeur - taille;
	if (largeur > 0)
	{
		while (zero == '0' && len < largeur)
		{
			string = ft_strjoin(string, "0", 1);
			len++;
		}
		while (len < largeur)
		{
			string = ft_strjoin(string, " ", 1);
			len++;
		}
	}
	return (string);
}

char	*ft_join_char(int largeur, char zero, char *string)
{
	int	len;
	int taille;

	len = 0;
	taille = ft_taille(string);
	largeur = largeur - taille;
	if (largeur > 0)
	{
		while (zero == '0' && len < largeur)
		{
			string = ft_strjoin("0", string, 2);
			len++;
		}
		while (len < largeur)
		{
			string = ft_strjoin(" ", string, 2);
			len++;
		}
	}
	return (string);
}

int		ft_check_largeur_char(char *args)
{
	int		a;
	char	*largeur;
	int		i_largeur;

	largeur = NULL;
	a = 0;
	while (args[a] && (!(args[a] <= '9' && args[a] >= '0')))
		a++;
	if (args[a - 1] == '.' || args[a] == '\0')
		return (0);
	while (args[a] && (args[a] <= '9' && args[a] >= '0'))
	{
		largeur = ft_strjoin_free_c(largeur, args[a]);
		a++;
	}
	i_largeur = ft_atoi(largeur);
	if (largeur)
		free(largeur);
	return (i_largeur);
}

int		ft_check_precision_char(char *args)
{
	int		index;
	int		i_precision;
	char	*precision;

	if ((index = ft_strchar(args, '.')) == -1)
		return (-1);
	index = index + 1;
	precision = NULL;
	while (args[index] && (args[index] <= '9' && args[index] >= '0'))
	{
		precision = ft_strjoin_free_c(precision, args[index]);
		index++;
	}
	i_precision = ft_atoi(precision);
	if (precision)
		free(precision);
	return (i_precision);
}
