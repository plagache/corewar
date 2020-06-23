/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <alagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 18:51:51 by plagache          #+#    #+#             */
/*   Updated: 2020/06/15 15:15:14 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "op.h"
#include "asm.h"

int		main(int ac, char **av)
{
	t_header	header;
	t_file		file;

	if (get_params(ac, av, &file) == FAILURE)
		return (EXIT_FAILURE);
	if (read_file(&file) == FAILURE)
		return (EXIT_FAILURE);
	if (parse_file(&file, &header) == FAILURE)
		return (EXIT_FAILURE);
	if (write_to(&file) == FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
