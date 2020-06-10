/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <alagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 15:33:57 by agardina          #+#    #+#             */
/*   Updated: 2020/06/10 17:45:23 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

//last -d prevails
int			set_d_flag(int ac, char **av, t_data *data, uint32_t *i)
{
	//check if next argument exist and is a number (charset +-1234566789)
	//	FAILURE USAGE
	//get cycle to dump and set dump flag
	//block both arguments
	char	*arg;

	arg = av[*i + 1];
	if (*i < (uint32_t)ac - 1
		&& ft_ischarset(NBR_CHARSET, arg, ft_strlen(arg)) == TRUE)
	{
		data->vm.cycle_to_dump = ft_atoi(arg);
		data->vm.dump ^= D_FLAG;
		(*i) += 2;
	}
	//print_error/usage
	return (FAILURE);
}

int			set_dump_flag(int ac, char **av, t_data *data, uint32_t *i)
{
	char	*arg;

	arg = av[*i + 1];
	if (*i < (uint32_t)ac - 1
		&& ft_ischarset(NBR_CHARSET, arg, ft_strlen(arg)) == TRUE)
	{
		data->vm.cycle_to_dump = ft_atoi(arg);
		data->vm.dump ^= DUMP_FLAG;
		(*i) += 2;
	}
	//print_error/usage
	return (FAILURE);
}

//-d [nbr] is 64 bytes
//-dump [nbr] should be 32
//-n [nbr] follows by player number
//add flags to usage
//ambiguous player name -n -d -dump are not accepted
//flag always followd by number
void		get_flags(int ac, char **av, t_data *data, uint32_t *i)
{
	while (*i < (uint32_t)ac)
	{
		if (ft_strequ(av[*i], "-d") && set_d_flag(ac, av, data, i) == FAILURE)
			deal_error(data, NO_NBR_ARGUMENT, USAGE);
		else if (ft_strequ(av[*i], "-dump")
				&& set_dump_flag(ac, av, data, i) == FAILURE)
			deal_error(data, NO_NBR_ARGUMENT, USAGE);
		else
			break ;
		(*i)++;
	}
}
