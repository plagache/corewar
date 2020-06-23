/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:35:07 by agardina          #+#    #+#             */
/*   Updated: 2020/06/08 15:35:09 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

static int32_t	store_direct(t_data *data, t_carriage *current, t_op_s *op)
{
	uint32_t	to_store;

	to_store = get_from_ram(data, current->pos + current->bytes_to_jump,
			op->dir_size);
	return ((int32_t)to_store);
}

static int32_t	store_indirect(t_data *data, t_carriage *current)
{
	uint32_t	to_store;
	int16_t		address;

	address = get_from_ram(data, current->pos + current->bytes_to_jump, 2);
	address = address % IDX_MOD;
	if (current->opcode != 3)
		to_store = get_from_ram(data, current->pos + address, 4);
	else
		to_store = address;
	return ((int32_t)to_store);
}

t_bool			store_arg(t_data *data, t_carriage *current, t_op_s *op,
	int8_t arg_type)
{
	t_bool	ret;
	int32_t	to_store;

	ret = true;
	if (arg_type == REG_CODE)
	{
		to_store = get_from_ram(data, current->pos + current->bytes_to_jump, 1);
		current->bytes_to_jump += 1;
		ret = (1 <= to_store && to_store <= 16);
	}
	else if (arg_type == DIR_CODE)
	{
		to_store = store_direct(data, current, op);
		current->bytes_to_jump += op->dir_size;
	}
	else if (arg_type == IND_CODE)
	{
		to_store = store_indirect(data, current);
		current->bytes_to_jump += 2;
	}
	else
		return (false);
	op->arg[op->nb_arg_stored] = to_store;
	return (ret);
}
