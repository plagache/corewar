/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/21 16:05:45 by agardina          #+#    #+#             */
/*   Updated: 2019/04/21 17:02:30 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *ptr;

	while (*alst)
	{
		ptr = (*alst)->next;
		(*del)((*alst)->content, (*alst)->content_size);
		free(*alst);
		*alst = NULL;
		*alst = ptr;
	}
}
