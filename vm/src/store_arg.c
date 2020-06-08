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

static int32_t	store_direct(t_data *data, t_carriage *current, t_op *op)
{
	int8_t		i;
	uint32_t	to_store;
	uint8_t		byte;

	i = 0;
	to_store = 0;
	while (i < op->dir_size)
	{
		to_store = to_store << 8;
		byte = get_from_ram(data, current->pos + current->bytes_to_jump + i, op->dir_size);
		to_store += byte;
		i++;
	}
	return ((int32_t)to_store);
}

static int32_t	store_indirect(t_data *data, t_carriage *current)
{
	int8_t		i;
	uint32_t	to_store;
	uint8_t		byte;
	int32_t		address;

	i = 0;
	to_store = 0;
	address = get_from_ram(data, current->pos + current->bytes_to_jump, 2);
	address = address % IDX_MOD;
	while (i < 2)
	{
		to_store = to_store << 8;
		byte = get_from_ram(data, current->pos + current->bytes_to_jump + i, 1);
		to_store += byte;
		i++;
	}
	return ((int32_t)to_store);
}

t_bool			store_arg(t_data *data, t_carriage *current, t_op *op,
	int8_t arg_type)
{
	t_bool	ret;
	int32_t	to_store;

	ret = true;
	if (arg_type == REG_CODE)
	{
		current->bytes_to_jump += 1;
		to_store = get_from_ram(data, current->pos + current->bytes_to_jump, 1);
		ret = (1 <= to_store && to_store <= 16);
	}
	else if (arg_type == DIR_CODE)
	{
		current->bytes_to_jump += op->dir_size;
		to_store = store_direct(data, current, op);
	}
	else
	{
		current->bytes_to_jump += 2;
		to_store = store_indirect(data, current);
	}
	op->arg[op->nb_arg_stored] = to_store;
	return (ret);
}
