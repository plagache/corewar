/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 14:50:35 by agardina          #+#    #+#             */
/*   Updated: 2020/06/05 14:50:36 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	config_fork_carriage(t_carriage *new, t_carriage *current,
	int32_t param)
{
	int32_t	i;

	i = 0;
	ft_bzero(new, sizeof(t_carriage));
	new->bytes_to_jump = 0;
	new->carry = current->carry;
	new->cycles_to_wait = -1;
	new->last_live = current->last_live;
	new->num = current->num + 1;
	new->pos = get_pos(current->pos + param);
	while (i < REG_NUMBER)
	{
		new->reg[i] = current->reg[i];
		i++;
	}
}

int32_t	op_lfork(t_data *data, t_carriage *current)
{
	int16_t shift;

	shift = get_from_ram(data, current->pos + 1, 2);
	add_head_carriage(data);
	config_fork_carriage(data->carriages, current, shift);
	current->bytes_to_jump += 2;
	return (0);
}

int32_t	op_fork(t_data *data, t_carriage *current)
{
	int16_t shift;

	shift = get_from_ram(data, current->pos + 1, 2);
	add_head_carriage(data);
	config_fork_carriage(data->carriages, current, shift % IDX_MOD);
	current->bytes_to_jump += 2;
	return (0);
}
