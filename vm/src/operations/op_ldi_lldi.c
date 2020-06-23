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

static void	verbose_ldi_lldi(t_data *data, t_carriage *current, int32_t reg_nb,
	int16_t addr[2])
{
	if ((data->vm.verbose & 0b0100) == 0)
		return ;
	print_proc_and_ft(current);
	if (current->opcode == 10)
	{
		addr[0] %= IDX_MOD;
		addr[1] %= IDX_MOD;
	}
	ft_printf("%d %d r%d\n", addr[0], addr[1], reg_nb);
	ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n",
		addr[0], addr[1], addr[0] + addr[1],
		(current->pos + addr[0] + addr[1]) % MEM_SIZE);
}

int32_t		op_lldi(t_data *data, t_carriage *current, t_op_s *op)
{
	int16_t	addr[2];

	op->dir_size = SMALL_DIR;
	op->nb_arg = 3;
	op->idx_mod = false;
	get_ocp(data, current, op);
	if (!check_ocp(data, current, op))
		return (-1);
	if (!ft_strchr("\x54\x64\x94\xA4\xD4\xE4", op->ocp & 0xFC))
		return (-1);
	if ((op->ocp & 0xFC) == 0x54 || (op->ocp & 0xFC) == 0x64)
		addr[0] = current->reg[op->arg[0] - 1];
	else
		addr[0] = op->arg[0];
	if ((op->ocp & 0xFC) == 0x54 || (op->ocp & 0xFC) == 0x94
		|| (op->ocp & 0xFC) == 0xD4)
		addr[1] = current->reg[op->arg[1] - 1];
	else
		addr[1] = op->arg[1];
	current->reg[op->arg[2] - 1] = get_from_ram(data,
		current->pos + addr[0] + addr[1], 4);
	current->carry = (current->reg[op->arg[2] - 1] == 0) ? 1 : 0;
	verbose_ldi_lldi(data, current, op->arg[2], addr);
	return (0);
}

int32_t		op_ldi(t_data *data, t_carriage *current, t_op_s *op)
{
	int16_t	addr[2];

	op->dir_size = SMALL_DIR;
	op->nb_arg = 3;
	op->idx_mod = true;
	get_ocp(data, current, op);
	if (!check_ocp(data, current, op))
		return (-1);
	if (!ft_strchr("\x54\x64\x94\xA4\xD4\xE4", op->ocp & 0xFC))
		return (-1);
	if ((op->ocp & 0xFC) == 0x54 || (op->ocp & 0xFC) == 0x64)
		addr[0] = current->reg[op->arg[0] - 1];
	else
		addr[0] = op->arg[0];
	if ((op->ocp & 0xFC) == 0x54 || (op->ocp & 0xFC) == 0x94
		|| (op->ocp & 0xFC) == 0xD4)
		addr[1] = current->reg[op->arg[1] - 1];
	else
		addr[1] = op->arg[1];
	current->reg[op->arg[2] - 1] = get_from_ram(data,
		current->pos + ((addr[0] + addr[1]) % IDX_MOD), 4);
	verbose_ldi_lldi(data, current, op->arg[2], addr);
	return (0);
}
