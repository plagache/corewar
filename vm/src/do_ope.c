/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_ope.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/04 12:35:38 by agardina          #+#    #+#             */
/*   Updated: 2020/06/04 12:35:39 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int32_t	do_ope(int32_t opcode, t_data *data, t_carriage *current, t_op_s *op)
{
	static const t_op_f ope_tab[16] = {&op_live, &op_ld, &op_st, &op_add,
	&op_sub, &op_and, &op_or, &op_xor, &op_zjmp, &op_ldi, &op_sti, &op_fork,
	&op_lld, &op_lldi, &op_lfork, &op_aff};

	return (ope_tab[opcode - 1](data, current, op));
}
