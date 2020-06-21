/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:19:55 by nabboufe          #+#    #+#             */
/*   Updated: 2018/12/29 15:15:43 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new_list;
	t_list		*first;

	if (!(lst))
		return (NULL);
	first = f(lst);
	new_list = first;
	if (!(new_list))
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
		new_list->next = f(lst);
		if (!(new_list->next))
			return (NULL);
		new_list = new_list->next;
	}
	return (first);
}
