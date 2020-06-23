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

static void	verbose_sti(t_data *data, t_carriage *current, int32_t reg_nb,
	int16_t addr[2])
{
	if ((data->vm.verbose & 0b0100) == 0)
		return ;
	print_proc_and_ft(current);
	addr[0] %= IDX_MOD;
	addr[1] %= IDX_MOD;
	ft_printf("r%d %d %d\n", reg_nb, addr[0], addr[1]);
	ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n",
		addr[0], addr[1], addr[0] + addr[1],
		(current->pos + addr[0] + addr[1]) % MEM_SIZE);
}

int32_t		op_sti(t_data *data, t_carriage *current, t_op_s *op)
{
	int16_t	addr[2];

	op->dir_size = SMALL_DIR;
	op->nb_arg = 3;
	op->idx_mod = true;
	get_ocp(data, current, op);
	if (!check_ocp(data, current, op))
		return (-1);
	if (!ft_strchr("\x54\x58\x64\x68\x74\x78", op->ocp & 0xFC))
		return (-1);
	if ((op->ocp & 0xFC) == 0x54 || (op->ocp & 0xFC) == 0x58)
		addr[0] = current->reg[op->arg[1] - 1];
	else
		addr[0] = op->arg[1];
	if ((op->ocp & 0xFC) == 0x54 || (op->ocp & 0xFC) == 0x64
		|| (op->ocp & 0xFC) == 0x74)
		addr[1] = current->reg[op->arg[2] - 1];
	else
		addr[1] = op->arg[2];
	write_in_ram(data, current->pos + ((addr[0] + addr[1]) % IDX_MOD),
		current->reg[op->arg[0] - 1]);
	verbose_sti(data, current, op->arg[0], addr);
	return (0);
}
