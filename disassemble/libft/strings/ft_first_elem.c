/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_first_elem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 11:48:21 by nabboufe          #+#    #+#             */
/*   Updated: 2018/12/29 15:14:06 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

struct s_begin		*ft_first_elem(void)
{
	t_begin		*begin;
	t_list_p	*l_1;

	if (!(begin = (t_begin *)malloc(sizeof(*begin))))
		return (NULL);
	if (!(l_1 = (t_list_p *)malloc(sizeof(*l_1))))
		return (NULL);
	l_1->data = NULL;
	l_1->next = NULL;
	begin->first_elem = l_1;
	begin->list = NULL;
	return (begin);
}
