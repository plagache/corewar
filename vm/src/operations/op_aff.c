/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 14:50:25 by agardina          #+#    #+#             */
/*   Updated: 2020/06/05 14:50:26 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int32_t	op_aff(t_data *data, t_carriage *current)
{
	t_ope	op;
	int8_t	c;

	op.dir_size = BIG_DIR;
	op.idx_mod = true;
	op.nb_arg = 1;
	get_ocp(data, current, &op);
	if (!check_ocp(data, current, &op))
		return (-1);
	if (0x40 != (op.ocp & 0xC0))
		return (-1);
	c = (current->reg[op.arg[0] - 1] % 256);
	printf("%c", (char)c);
	return (0);
}
