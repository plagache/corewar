/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_st.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 14:51:21 by agardina          #+#    #+#             */
/*   Updated: 2020/06/05 14:51:22 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int32_t	op_st(t_data *data, t_carriage *current)
{
	t_ope	op;

	op.dir_size = BIG_DIR;
	op.nb_arg = 2;
	op.idx_mod = true;
	get_ocp(data, current, &op);
	if (!check_ocp(data, current, &op))
		return (-1);
	if (!ft_strchr("\x50\x70", op.ocp & 0xF0))
		return (-1);
	if ((op.ocp & 0xF0) == 0x50)
		current->reg[op.arg[1] - 1] = current->reg[op.arg[0] - 1];
	else
		write_in_ram(data, current->pos + (op.arg[1] % IDX_MOD),
			current->reg[op.arg[0] - 1]);
	return (0);
}
