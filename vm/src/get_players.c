/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_players.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 15:34:18 by agardina          #+#    #+#             */
/*   Updated: 2020/06/10 17:04:56 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

static t_bool	file_name_ok(char *name)
{
	uint32_t len;

	len = ft_strlen(name);
	if (len <= 4 || !ft_strequ(name + len - 4, ".cor"))
		return (false);
	return (true);
}

void			get_players(int ac, char **av, t_data *data, uint32_t *i)
{
	uint32_t		player_num;

	player_num = 0;
	while (*i < (uint32_t)ac)
	{
		if (4 < (++data->vm.nb_players))
			deal_error(data, TOO_MANY_CHAMP, USAGE);
		player_num = get_player_num(av, data, i);
		data->players[player_num - 1].num = player_num;
		if (file_name_ok(av[*i]))
		{
			get_player_info(av[*i], data, player_num);
			if (data->players[player_num - 1].code_size <= 0 ||
				682 < data->players[player_num - 1].code_size)
				deal_error(data, CODE_SIZE, NO_USAGE);
		}
		else
			deal_error(data, BAD_FILE_NAME, NO_USAGE);
		(*i)++;
	}
}
