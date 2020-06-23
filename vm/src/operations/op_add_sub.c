/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_add.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 14:50:19 by agardina          #+#    #+#             */
/*   Updated: 2020/06/05 14:50:20 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

static void	verbose_add_sub(t_data *data, t_carriage *current, t_op_s *op)
{
	if ((data->vm.verbose & 0b0100) == 0)
		return ;
	print_proc_and_ft(current);
	ft_printf("r%d r%d r%d\n", op->arg[0], op->arg[1], op->arg[2]);
}

int32_t		op_sub(t_data *data, t_carriage *current, t_op_s *op)
{
	op->dir_size = 4;
	op->nb_arg = 3;
	op->idx_mod = true;
	get_ocp(data, current, op);
	if (!check_ocp(data, current, op))
		return (-1);
	if (0x54 != (op->ocp & 0xFC))
		return (-1);
	current->reg[op->arg[2] - 1] = current->reg[op->arg[0] - 1] -
		current->reg[op->arg[1] - 1];
	if (current->reg[op->arg[2] - 1] == 0)
		current->carry = 1;
	else
		current->carry = 0;
	verbose_add_sub(data, current, op);
	return (0);
}

int32_t		op_add(t_data *data, t_carriage *current, t_op_s *op)
{
	op->dir_size = 4;
	op->nb_arg = 3;
	op->idx_mod = true;
	get_ocp(data, current, op);
	if (!check_ocp(data, current, op))
		return (-1);
	if (0x54 != (op->ocp & 0xFC))
		return (-1);
	current->reg[op->arg[2] - 1] = current->reg[op->arg[0] - 1] +
		current->reg[op->arg[1] - 1];
	if (current->reg[op->arg[2] - 1] == 0)
		current->carry = 1;
	else
		current->carry = 0;
	verbose_add_sub(data, current, op);
	return (0);
}
