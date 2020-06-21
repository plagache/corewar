/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:23:37 by nabboufe          #+#    #+#             */
/*   Updated: 2018/12/29 15:15:55 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*elem;

	if (!(elem = (t_list *)malloc(sizeof(elem) * content_size)))
		return (NULL);
	if (!(content))
	{
		elem->content = NULL;
		elem->content_size = 0;
	}
	else
	{
		if (!(elem->content = (void *)malloc(sizeof(content))))
			return (NULL);
		ft_memcpy(elem->content, content, content_size);
		elem->content_size = content_size;
	}
	elem->next = NULL;
	return (elem);
}
