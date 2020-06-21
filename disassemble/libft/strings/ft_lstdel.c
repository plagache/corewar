/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:04:59 by nabboufe          #+#    #+#             */
/*   Updated: 2018/12/29 15:15:18 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*tmp;

	if (!(*alst))
		return ;
	while (*alst != NULL)
	{
		tmp = (*alst)->next;
		(*del)((*alst)->content, (*alst)->content_size);
		if (alst)
			free(*alst);
		*alst = tmp;
	}
}
