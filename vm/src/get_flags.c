/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <alagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 15:33:57 by agardina          #+#    #+#             */
/*   Updated: 2020/06/15 12:36:56 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int			set_d_flag(int ac, char **av, t_data *data, uint32_t *i)
{
	char	*arg;

	if (data->vm.dump != 0)
		deal_error(data, NO_NBR_ARGUMENT, USAGE);
	arg = av[*i + 1];
	if (*i < (uint32_t)ac - 1
		&& ft_ischarset(NBR_CHARSET, arg, ft_strlen(arg)) == TRUE)
	{
		data->vm.cycle_to_dump = ft_atoi(arg);
		data->vm.dump = D_FLAG;
		(*i) += 2;
		return (SUCCESS);
	}
	deal_error(data, NO_NBR_ARGUMENT, USAGE);
	return (FAILURE);
}

int			set_dump_flag(int ac, char **av, t_data *data, uint32_t *i)
{
	char	*arg;

	if (data->vm.dump != 0)
		deal_error(data, NO_NBR_ARGUMENT, USAGE);
	arg = av[*i + 1];
	if (*i < (uint32_t)ac - 1
		&& ft_ischarset(NBR_CHARSET, arg, ft_strlen(arg)) == TRUE)
	{
		data->vm.cycle_to_dump = ft_atoi(arg);
		data->vm.dump ^= DUMP_FLAG;
		(*i) += 2;
		return (SUCCESS);
	}
	deal_error(data, NO_NBR_ARGUMENT, USAGE);
	return (FAILURE);
}

void		get_flags(int ac, char **av, t_data *data, uint32_t *i)
{
	while (*i < (uint32_t)ac)
	{
		if (ft_strequ(av[*i], "-d"))
			set_d_flag(ac, av, data, i);
		else if (ft_strequ(av[*i], "-dump"))
			set_dump_flag(ac, av, data, i);
		else
			break;
	}
}

