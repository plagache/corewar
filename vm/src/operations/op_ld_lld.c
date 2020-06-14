/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_ld.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 14:50:42 by agardina          #+#    #+#             */
/*   Updated: 2020/06/05 14:50:43 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int32_t	op_lld(t_data *data, t_carriage *current)
{
	t_ope op;

	op.dir_size = BIG_DIR;
	op.nb_arg = 2;
	op.ocp = 0;
	op.idx_mod = false;
	get_ocp(data, current, &op);
	if (!check_ocp(data, current, &op))
		return (-1);
	if (!ft_strchr("\x90\xD0", op.ocp & 0xF0))
		return (-1);
	current->reg[op.arg[1] - 1] = op.arg[0];
	current->carry = (current->reg[op.arg[1] - 1] == 0) ? 1 : 0;
	return (0);
}

int32_t	op_ld(t_data *data, t_carriage *current)
{
	t_ope op;

	op.dir_size = BIG_DIR;
	op.nb_arg = 2;
	op.idx_mod = true;
	get_ocp(data, current, &op);
	if (!check_ocp(data, current, &op))
		return (-1);
	if (!ft_strchr("\x90\xD0", op.ocp & 0xF0))
		return (-1);
	current->reg[op.arg[1] - 1] = op.arg[0];
	current->carry = (current->reg[op.arg[1] - 1] == 0) ? 1 : 0;
	return (0);
}
