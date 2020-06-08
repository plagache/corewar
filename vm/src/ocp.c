/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:35:02 by agardina          #+#    #+#             */
/*   Updated: 2020/06/08 15:35:03 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

t_bool	check_ocp(t_data *data, t_carriage *current, t_op *op)
{
	int8_t	pair;
	int8_t	i;
	int8_t	mask;
	t_bool	ret;

	i = 0;
	mask = 0xC0;
	ret = true;
	while (i < op->nb_arg)
	{
		pair = (op->ocp & mask) >> ((3 - i) * 2);
		if (pair != REG_CODE || pair != DIR_CODE || pair != IND_CODE)
			return (false);
		ret = (ret == false) ? false : store_arg(data, current, op, pair);
		op->nb_arg_stored++;
		i++;
		mask = mask >> 2;
	}
	return (ret);
}

void	get_ocp(t_data *data, t_carriage *current, t_op *op)
{
	current->bytes_to_jump += 1;
	op->ocp = (int8_t)get_from_ram(data, current->pos + 1, 1);
}
