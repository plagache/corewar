/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_num.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 15:34:11 by agardina          #+#    #+#             */
/*   Updated: 2020/06/03 15:34:12 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

static int	check_num_arg(t_data *data, char *str)
{
	long arg_num;

	arg_num = ft_atol(str);
	if (arg_num < INT_MIN || INT_MAX < arg_num)
		deal_error(data, "");
	return ((int)arg_num);
}

static int	check_player_num(t_data *data, uint32_t player_num,
t_bool num_chosen_by_user)
{
	uint32_t i;

	i = 0;
	if (num_chosen_by_user == false ||
	(num_chosen_by_user == true
	&& data->players[player_num - 1].num == player_num))
	{
		while (i < MAX_PLAYERS)
		{
			if (data->players[i].num == 0)
				return (i + 1);
			else
				i++;
		}
	}
	return (player_num);
}

uint32_t	get_player_num(char **av, t_data *data, uint32_t *i)
{
	int		player_num;
	t_bool	num_chosen_by_user;

	num_chosen_by_user = false;
	player_num = 0;
	if (ft_strnequ(av[*i], "-n", 2))
	{
		if (ft_strequ(av[*i], "-n"))
			player_num = check_num_arg(data, av[++(*i)]);
		else
			player_num = check_num_arg(data, av[*i] + 2);
		if (player_num < 1 || MAX_PLAYERS < player_num)
			deal_error(data, PLAYER_NUM_ERR);
		(*i)++;
		num_chosen_by_user = true;
	}
	player_num = check_player_num(data, player_num, num_chosen_by_user);
	return (player_num);
}
