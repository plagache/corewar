/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 10:45:48 by agardina          #+#    #+#             */
/*   Updated: 2020/06/02 10:45:49 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int			main(int ac, char **av)
{
	t_data	data;

	if (ac < 2)
		deal_error(&data, PRINT_USAGE);
	init_data(&data);
	ft_read(ac, av, &data);
	prepare_carriages(&data);
	prepare_arena(&data);
	announce_players(&data);
	do_cycles(&data);
	announce_winner(&data);
	free_data(&data);
	return (0);
}
