/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <alagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 15:33:57 by agardina          #+#    #+#             */
/*   Updated: 2020/06/09 17:44:03 by alagache         ###   ########.fr       */
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
	if (*i < (uint32_t)ac - 1
		&& ft_ischarset(NBR_CHARSET, av[*i + 1], ft_strlen(av[*i + 1])) == TRUE)
	{
		data->vm.cycle_to_dump = ft_atoi(av[*i + 1]);
		data->vm.dump ^= D_FLAG;
		av[*i][0] = '\0';
		av[*i + 1][0] = '\0';
		(*i)++;
	}
	//print_error/usage
	return (FAILURE);
}

int			set_dump_flag(int ac, char **av, t_data *data, uint32_t *i)
{
	if (*i < (uint32_t)ac - 1
		&& ft_ischarset(NBR_CHARSET, av[*i + 1], ft_strlen(av[*i + 1])) == TRUE)
	{
		data->vm.cycle_to_dump = ft_atoi(av[*i + 1]);
		data->vm.dump ^= DUMP_FLAG;
		av[*i][0] = '\0';
		av[*i + 1][0] = '\0';
		(*i)++;
	}
	//print_error/usage
	return (FAILURE);
}

//-d [nbr] is 64 bytes
//-dump [nbr] should be 32
//-n [nbr] follows by player number
//add flags to usage
//unambiguous player name -n -d -dump are not acepted
//flag always followd by number
int		get_flags(int ac, char **av, t_data *data, uint32_t *i)
{
	while (*i < (uint32_t)ac)
	{
		if (ft_strequ(av[*i], "-d") && set_d_flag(ac, av, data, i) == FAILURE)
			return (FAILURE);
		else if (ft_strequ(av[*i], "-dump")
				&& set_dump_flag(ac, av, data, i) == FAILURE)
			return (FAILURE);
		else
			break ;
		(*i)++;
	}
}
