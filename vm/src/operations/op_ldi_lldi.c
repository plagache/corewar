/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ldi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 14:50:48 by agardina          #+#    #+#             */
/*   Updated: 2020/06/05 14:50:49 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int32_t	op_lldi(t_data *data, t_carriage *current)
{
	t_ope	op;
	int16_t	addr;

	op.dir_size = SMALL_DIR;
	op.nb_arg = 3;
	op.idx_mod = false;
	get_ocp(data, current, &op);
	if (!check_ocp(data, current, &op))
		return (-1);
	if (!ft_strchr("\x54\x64\x94\xA4\xD4\xE4", op.ocp & 0xFC))
		return (-1);
	if ((op.ocp & 0xFC) == 0x54 || (op.ocp & 0xFC) == 0x64)
		addr = current->reg[op.arg[0] - 1];
	else
		addr = op.arg[0];
	if ((op.ocp & 0xFC) == 0x54 || (op.ocp & 0xFC) == 0x94
		|| (op.ocp & 0xFC) == 0xD4)
		addr += current->reg[op.arg[1] - 1];
	else
		addr += op.arg[1];
	current->reg[op.arg[2] - 1] = get_from_ram(data,
		current->pos + addr, 4);
	current->carry = (current->reg[op.arg[2] - 1] == 0) ? 1 : 0;
	return (0);
}

int32_t	op_ldi(t_data *data, t_carriage *current)
{
	t_ope	op;
	int16_t	addr;

	op.dir_size = SMALL_DIR;
	op.nb_arg = 3;
	op.idx_mod = true;
	get_ocp(data, current, &op);
	if (!check_ocp(data, current, &op))
		return (-1);
	if (!ft_strchr("\x54\x64\x94\xA4\xD4\xE4", op.ocp & 0xFC))
		return (-1);
	if ((op.ocp & 0xFC) == 0x54 || (op.ocp & 0xFC) == 0x64)
		addr = current->reg[op.arg[0] - 1];
	else
		addr = op.arg[0];
	if ((op.ocp & 0xFC) == 0x54 || (op.ocp & 0xFC) == 0x94
		|| (op.ocp & 0xFC) == 0xD4)
		addr += current->reg[op.arg[1] - 1];
	else
		addr += op.arg[1];
	current->reg[op.arg[2] - 1] = get_from_ram(data,
		current->pos + (addr % IDX_MOD), 4);
	current->carry = (current->reg[op.arg[2] - 1] == 0) ? 1 : 0;
	return (0);
}
