/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_carriage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 14:52:44 by agardina          #+#    #+#             */
/*   Updated: 2020/06/05 14:52:49 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

static t_carriage	*delete_head(t_data *data, t_carriage *head)
{
	t_carriage	*new_head;

	new_head = NULL;
	if (!head->next)
	{
		free(head);
		data->carriages = NULL;
	}
	else
	{
		new_head = head->next;
		free(head);
		data->carriages = new_head;
	}
	return (new_head);
}

void				delete_all_carriages(t_data *data)
{
	t_carriage *current;
	t_carriage *tmp;

	current = data->carriages;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	data->carriages = NULL;
}

t_carriage			*delete_one_carriage(t_data *data, t_carriage *current)
{
	t_carriage *new_current;

	if (!current)
		return (NULL);
	if (current == data->carriages)
		return (delete_head(data, current));
	new_current = current->next;
	if (current->next)
		current->next->previous = current->previous;
	free(current);
	return (new_current);
}
