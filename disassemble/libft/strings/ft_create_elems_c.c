/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elems_c.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 12:17:37 by nabboufe          #+#    #+#             */
/*   Updated: 2018/12/29 15:13:56 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

void	ft_create_elems_c(struct s_begin **begin, void *data)
{
	t_list_p		*p_l;
	t_list_p		*p_n;

	if (!(*begin))
		return ;
	p_l = (t_list_p*)(*begin)->list;
	p_n = NULL;
	if (!(p_n = malloc(sizeof(*p_n))))
		return ;
	p_n->data = data;
	if (p_l == NULL)
	{
		(*begin)->first_elem->next = p_n;
		p_n->next = NULL;
	}
	else
	{
		p_n->next = p_l->next;
		p_l->next = p_n;
	}
	(*begin)->list = p_n;
}
