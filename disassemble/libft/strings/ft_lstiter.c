/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:14:43 by nabboufe          #+#    #+#             */
/*   Updated: 2018/12/29 15:15:33 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list		*tmp;

	if (!(lst))
		return ;
	while (lst != NULL)
	{
		tmp = (lst)->next;
		(*f)(lst);
		(lst) = tmp;
	}
}
