/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_whereis.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/29 15:25:57 by nabboufe          #+#    #+#             */
/*   Updated: 2018/12/29 20:31:56 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_whereis(const char *str, char c, int len)
{
	int i;

	i = 0;
	if (!(str))
		return (-1);
	while (str[i] != c && len > i && str[i])
		i++;
	if (str[i] == c)
		return (i);
	else if (i > 0)
		return (-2);
	return (-1);
}
