/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 15:34:24 by agardina          #+#    #+#             */
/*   Updated: 2020/06/03 15:34:24 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

static void	init_vm(t_data *data)
{
	data->vm.cycle_to_die = CYCLE_TO_DIE;
	data->vm.dump = -1;
}

void		init_data(t_data *data)
{
	ft_bzero(data, sizeof(*data));
	init_vm(data);
}
