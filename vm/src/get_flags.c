/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <alagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 15:33:57 by agardina          #+#    #+#             */
/*   Updated: 2020/06/09 12:52:01 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void			set_d_flag(int ac, char **av, t_data *data, uint32_t *i)
{
	if (*i < (uint32_t)ac - 1)
	{
		(*i)++;
		data->vm.cycle_to_dump = ft_atoi(av[*i]);
		data->vm.dump ^= D_FLAG;
	}
}

void			set_dump_flag(int ac, char **av, t_data *data, uint32_t *i)
{
	if (*i < (uint32_t)ac - 1)
	{
		(*i)++;
		data->vm.cycle_to_dump = ft_atoi(av[*i]);
		data->vm.dump ^= DUMP_FLAG;
	}
}

//-d is 64 bytes
//--dump should be 32
//add flags to usage
void			get_flags(int ac, char **av, t_data *data, uint32_t *i)
{
	while (*i < (uint32_t)ac)
	{
		if (ft_strequ(av[*i], "-d"))
			set_d_flag(ac, av, data, i);
		else if (ft_strequ(av[*i], "--dump"))
			set_dump_flag(ac, av, data, i);
		else
			break ;
		(*i)++;
	}
}
