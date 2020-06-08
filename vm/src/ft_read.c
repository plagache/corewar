/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 15:33:50 by agardina          #+#    #+#             */
/*   Updated: 2020/06/03 15:33:51 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void			ft_read(int ac, char **av, t_data *data)
{
	uint32_t i;

	i = 1;
	get_flags(ac, av, data, &i);
	get_players(ac, av, data, &i);
}
