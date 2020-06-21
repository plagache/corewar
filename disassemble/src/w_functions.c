/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w_functions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 17:49:26 by nabboufe          #+#    #+#             */
/*   Updated: 2020/06/19 23:51:08 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/disassemble.h"

void					w_header(t_corefile *file)
{
	write(file->fd, ".name \"", 7);
	ft_putstr_fd(file->header.prog_name, file->fd);
	write(file->fd, "\"\n", 2);
	write(file->fd, ".comment \"", 10);
	ft_putstr_fd(file->header.comment, file->fd);
	write(file->fd, "\"\n\n", 3);
}

static unsigned	int		w_program_op(uint8_t op_code, t_corefile *file)
{
	if (op_code > 0 && op_code < 17)
	{
		ft_putstr_fd(g_op_tab[op_code - 1].keyword, file->fd);
		write(file->fd, " ", 2);
	}
	return (1);
}

static void				wrong_cor(t_corefile *file)
{
	write(1, "Error: cor file not valid\n", 27);
	close(file->fd);
	exit(0);
}

static unsigned	int		write_lzf(uint8_t op_code, t_corefile *file)
{
	int16_t		param;
	int32_t		param1;

	param = 0;
	if (op_code == 1)
	{
		ft_memcpy(&param1, file->champ + file->index, 4);
		param1 = ft_4byteswap(param1);
		write(file->fd, "%", 1);
		ft_putnbr_fd(param1, file->fd);
		write(file->fd, " ", 1);
		return (4);
	}
	else if (op_code == 9 | op_code == 12 | op_code == 15)
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

unsigned int			w_program(t_corefile *file)
{
	uint8_t		op_code;
	uint8_t		encode;

	encode = 0;
	if (!check_type(file->champ, file->index))
		wrong_cor(file);
	op_code = file->champ[file->index];
	file->index += w_program_op(op_code, file);
	if (g_op_tab[op_code - 1].carry == 1)
	{
		encode = file->champ[file->index++];
		if (((encode & 0b11000000) >> 6))
			file->index += w_param(((encode & 0b11000000) >> 6),
				op_code, file);
		if (((encode & 0b00110000) >> 4))
			file->index += w_param(((encode & 0b00110000) >> 4),
				op_code, file);
		if (((encode & 0b00001100) >> 2))
			file->index += w_param(((encode & 0b00001100) >> 2),
				op_code, file);
	}
	else
		file->index += write_lzf(op_code, file);
	write(file->fd, "\n", 1);
	return (0);
}
