/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_list.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:30:50 by nabboufe          #+#    #+#             */
/*   Updated: 2018/12/29 15:19:43 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <unistd.h>

void	ft_putstr_list(t_list_p *current_e)
{
	if (current_e->data == NULL)
		return ;
	write(1, (char *)current_e->data, ft_strlen((char *)current_e->data));
}
