/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_params.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/19 19:30:19 by nabboufe          #+#    #+#             */
/*   Updated: 2020/06/19 23:51:33 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/disassemble.h"

static unsigned int		w_dir(unsigned int type, uint8_t op_code,
	t_corefile *file)
{
	int64_t param;

	param = 0;
	if (type == DIR_CODE && g_op_tab[op_code - 1].direct_size == 0)
	{
		ft_memcpy(&param, file->champ + file->index, 4);
		param = ft_4byteswap(param);
		write(file->fd, "%", 1);
		ft_putnbr_fd(param, file->fd);
		write(file->fd, " ", 1);
		return (4);
	}
	else if (type == DIR_CODE && g_op_tab[op_code - 1].direct_size == 1)
	{
		ft_memcpy(&param, file->champ + file->index, 2);
		param = ft_2byteswap(param);
		write(file->fd, "%", 1);
		ft_putnbr_fd(param, file->fd);
		write(file->fd, " ", 1);
		return (2);
	}
	return (0);
}

unsigned int			w_param(unsigned int type, uint8_t op_code,
	t_corefile *file)
{
	int64_t	param;

	param = 0;
	if (type == REG_CODE)
	{
		ft_memcpy(&param, file->champ + file->index, 1);
		write(file->fd, "r", 1);
		ft_putnbr_fd(param, file->fd);
		write(file->fd, " ", 1);
		return (1);
	}
	else if (type == IND_CODE)
	{
		ft_memcpy(&param, file->champ + file->index, 2);
		param = ft_2byteswap(param);
		write(file->fd, ":", 1);
		ft_putnbr_fd(param, file->fd);
		write(file->fd, " ", 1);
		return (2);
	}
	else if (type == DIR_CODE)
		return (w_dir(type, op_code, file));
	return (0);
}
