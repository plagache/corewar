/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 15:33:57 by agardina          #+#    #+#             */
/*   Updated: 2020/06/03 15:33:58 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void			get_flags(int ac, char **av, t_data *data, uint32_t *i)
{
	while (*i < (uint32_t)ac)
	{
		if (ft_strequ(av[*i], "-dump"))
		{
			if (*i < (uint32_t)ac - 1)
			{
				(*i)++;
				data->vm.dump = ft_atoi(av[*i]);
			}
		}
		else
			break ;
		(*i)++;
	}
}
