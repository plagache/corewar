/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_sti.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 14:51:26 by agardina          #+#    #+#             */
/*   Updated: 2020/06/05 14:51:27 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int32_t	op_sti(t_data *data, t_carriage *current)
{
	t_ope	op;
	int16_t	addr;

	op.dir_size = SMALL_DIR;
	op.nb_arg = 3;
	op.idx_mod = true;
	get_ocp(data, current, &op);
	if (!check_ocp(data, current, &op))
		return (-1);
	if (!ft_strchr("\x54\x58\x64\x68\x74\x78", op.ocp & 0xFC))
		return (-1);
	if ((op.ocp & 0xFC) == 0x54 || (op.ocp & 0xFC) == 0x58)
		addr = current->reg[op.arg[1] - 1];
	else
		addr = op.arg[1];
	if ((op.ocp & 0xFC) == 0x54 || (op.ocp & 0xFC) == 0x64
		|| (op.ocp & 0xFC) == 0x74)
		addr += current->reg[op.arg[2] - 1];
	else
		addr += op.arg[2];
	write_in_ram(data, current->pos + (addr % IDX_MOD),
		current->reg[op.arg[0] - 1]);
	current->carry = (current->reg[op.arg[0] - 1] == 0) ? 1 : 0;
	return (0);
}
