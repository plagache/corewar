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

t_bool	check_ocp(t_data *data, t_carriage *current, t_op_s *op)
{
	int8_t	pair;
	int8_t	i;
	int32_t	mask;
	t_bool	ret;

	i = 0;
	mask = 0xC0;
	op->nb_arg_stored = 0;
	op->ocp_validity = true;
	while (i < op->nb_arg)
	{
		pair = (op->ocp & mask) >> ((3 - i) * 2);
		ret = store_arg(data, current, op, pair);
		op->ocp_validity = (op->ocp_validity == false) ?
			false : ret;
		op->nb_arg_stored++;
		i++;
		mask >>= 2;
	}
	return (op->ocp_validity);
}

void	get_ocp(t_data *data, t_carriage *current, t_op_s *op)
{
	current->bytes_to_jump += 1;
	op->ocp = (int8_t)get_from_ram(data, current->pos + 1, 1);
}
