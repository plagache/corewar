/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utilities.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 14:33:22 by damboule          #+#    #+#             */
/*   Updated: 2019/04/09 19:35:21 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_downcase(char *c)
{
	int a;

	a = 0;
	while (c[a])
	{
		if (c[a] >= 'A' && c[a] <= 'Z')
			c[a] = c[a] + 32;
		a++;
	}
}

char	*ft_strrev(char *nombre)
{
	char	*new;
	int		a;
	int		b;

	a = 0;
	b = ft_strlen(nombre) - 1;
	new = (char *)malloc(sizeof(char ) * (b + 1));
	if (new == NULL)
		return (NULL);
	while (b >= 0)
	{
		new[a] = nombre[b];
		a++;
		b--;
	}
	new[a] = '\0';
	if (nombre)
		free(nombre);
	return (new);
}

void	ft_aff_char(char occur, int nb)
{
	while (nb > 0)
	{
		ft_putchar(occur);
		nb--;
	}
}

char	*ft_strndup(char *string, int len, int truth)
{
	char	*copy;
	int		a;

	a = 0;
	copy = (char *)malloc(sizeof(char) * len + 1);
	if (copy == NULL)
		return (NULL);
	while (a < len)
	{
		copy[a] = string[a];
		a++;
	}
	copy[a] = '\0';
	if (truth == 1 && string)
		free(string);
	return (copy);
}

char	*ft_strjoin_free_c(char *s1, char s2)
{
	int		a;
	char	*buffer;

	if (s1 != NULL)
	{
		a = ft_strlen(s1);
		buffer = (char *)malloc(sizeof(char) * (a + 2));
		if (buffer == NULL)
			return (NULL);
		buffer = ft_strcpy(buffer, s1);
		buffer[a] = s2;
		buffer[a + 1] = '\0';
	}
	else
	{
		buffer = (char *)malloc(sizeof(char) * 2);
		buffer[0] = s2;
		buffer[1] = '\0';
	}
	if (s1)
		free(s1);
	return (buffer);
}
