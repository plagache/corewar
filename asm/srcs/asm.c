/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 18:51:51 by plagache          #+#    #+#             */
/*   Updated: 2020/05/27 15:19:15 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "op.h"
#include "asm.h"

int		main(int ac, char **av)
{
	t_header	header;
	t_cor		cor;
	t_file		file;

	if (get_params(ac, av, &file) == FAILURE)
		return (EXIT_FAILURE);
	if (read_file(&file) == FAILURE)
		return (EXIT_FAILURE);
	if (parse_file(&file, &header, &cor) == FAILURE)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
	/*
	(void)cor;
	(void)header;
	write_file(&file, &cor);
	*/
}