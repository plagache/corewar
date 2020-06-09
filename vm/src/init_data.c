/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <alagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 15:34:24 by agardina          #+#    #+#             */
/*   Updated: 2020/06/09 13:55:32 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

static void	init_vm(t_data *data)
{
	data->vm.cycle_to_die = CYCLE_TO_DIE;
	data->vm.cycle_to_dump = -1;
	data->vm.dump = 0;
}

void		init_data(t_data *data)
{
	ft_bzero(data, sizeof(*data));
	init_vm(data);
}
