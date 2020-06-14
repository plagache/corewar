/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 14:50:30 by agardina          #+#    #+#             */
/*   Updated: 2020/06/05 14:50:31 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int32_t	op_xor(t_data *data, t_carriage *current)
{
	t_ope	op;

	op.dir_size = BIG_DIR;
	op.idx_mod = true;
	op.nb_arg = 3;
	get_ocp(data, current, &op);
	if (!check_ocp(data, current, &op))
		return (-1);
	if (!ft_strchr("\x54\x64\x74\x94\xA4\xB4\xD4\xE4\xF4", op.ocp & 0xFC))
		return (-1);
	if ((op.ocp & 0xFC) == 0x54 || (op.ocp & 0xFC) == 0x64
		|| (op.ocp & 0xFC) == 0x74)
		current->reg[op.arg[2] - 1] = current->reg[op.arg[0] - 1];
	else
		current->reg[op.arg[2] - 1] = op.arg[0];
	if ((op.ocp & 0xFC) == 0x54 || (op.ocp & 0xFC) == 0x94
		|| (op.ocp & 0xFC) == 0xD4)
		current->reg[op.arg[2] - 1] ^= current->reg[op.arg[1] - 1];
	else
		current->reg[op.arg[2] - 1] ^= op.arg[1];
	current->carry = (current->reg[op.arg[2] - 1] == 0) ? 1 : 0;
	return (0);
}

int32_t	op_or(t_data *data, t_carriage *current)
{
	t_ope	op;

	op.dir_size = BIG_DIR;
	op.idx_mod = true;
	op.nb_arg = 3;
	get_ocp(data, current, &op);
	if (!check_ocp(data, current, &op))
		return (-1);
	if (!ft_strchr("\x54\x64\x74\x94\xA4\xB4\xD4\xE4\xF4", op.ocp & 0xFC))
		return (-1);
	if ((op.ocp & 0xFC) == 0x54 || (op.ocp & 0xFC) == 0x64
		|| (op.ocp & 0xFC) == 0x74)
		current->reg[op.arg[2] - 1] = current->reg[op.arg[0] - 1];
	else
		current->reg[op.arg[2] - 1] = op.arg[0];
	if ((op.ocp & 0xFC) == 0x54 || (op.ocp & 0xFC) == 0x94
		|| (op.ocp & 0xFC) == 0xD4)
		current->reg[op.arg[2] - 1] |= current->reg[op.arg[1] - 1];
	else
		current->reg[op.arg[2] - 1] |= op.arg[1];
	current->carry = (current->reg[op.arg[2] - 1] == 0) ? 1 : 0;
	return (0);
}

int32_t	op_and(t_data *data, t_carriage *current)
{
	t_ope	op;

	op.dir_size = BIG_DIR;
	op.idx_mod = true;
	op.nb_arg = 3;
	get_ocp(data, current, &op);
	if (!check_ocp(data, current, &op))
		return (-1);
	if (!ft_strchr("\x54\x64\x74\x94\xA4\xB4\xD4\xE4\xF4", op.ocp & 0xFC))
		return (-1);
	if ((op.ocp & 0xFC) == 0x54 || (op.ocp & 0xFC) == 0x64
		|| (op.ocp & 0xFC) == 0x74)
		current->reg[op.arg[2] - 1] = current->reg[op.arg[0] - 1];
	else
		current->reg[op.arg[2] - 1] = op.arg[0];
	if ((op.ocp & 0xFC) == 0x54 || (op.ocp & 0xFC) == 0x94
		|| (op.ocp & 0xFC) == 0xD4)
		current->reg[op.arg[2] - 1] &= current->reg[op.arg[1] - 1];
	else
		current->reg[op.arg[2] - 1] &= op.arg[1];
	current->carry = (current->reg[op.arg[2] - 1] == 0) ? 1 : 0;
	return (0);
}
