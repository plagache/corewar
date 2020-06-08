/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_zjmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 14:51:59 by agardina          #+#    #+#             */
/*   Updated: 2020/06/05 14:51:59 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

int32_t	op_zjmp(t_data *data, t_carriage *current)
{
	int16_t shift;

	shift = 0;
	if (current->carry == 0)
		return (-1);
	shift = get_from_ram(data, current->pos + 1, 2);
	current->pos = get_pos(current->pos + shift);
	return (0);
}
