/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 15:25:04 by nabboufe          #+#    #+#             */
/*   Updated: 2020/06/19 23:28:36 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/disassemble.h"
#include <fcntl.h>

static			uint8_t g_type[4] = {
	0,
	T_REG,
	T_DIR,
	T_IND
};

int				read_file(const char *filepath, t_uint8file *file)
{
	int			fd;
	size_t		ret;

	fd = 0;
	if (filepath)
		fd = open(filepath, O_RDONLY);
	if (fd < 0)
		return (0);
	uint8file_init(file, 1);
	while ((ret = read(fd, file->content + file->length,
			file->capacity - file->length)) > 0)
	{
		file->length += ret;
		if (file->capacity < file->length + 1)
			uint8file_resize(file, file->capacity * 2);
	}
	close(fd);
	return (1);
}

int				check_type(uint8_t *champ, unsigned int pc)
{
	uint8_t		op_code;
	uint8_t		encoded;
	uint8_t		valid_count;

	op_code = champ[pc % MEM_SIZE] - 1;
	if (!g_op_tab[op_code].carry)
		return (1);
	encoded = champ[(pc + 1) % MEM_SIZE];
	valid_count = 0;
	if (g_type[((encoded & 0b11000000) >> 6)]
			& g_op_tab[op_code].type_arr[0])
		valid_count += 1;
	if (g_type[((encoded & 0b00110000) >> 4)]
			& g_op_tab[op_code].type_arr[1])
		valid_count += 1;
	if (g_type[((encoded & 0b00001100) >> 2)]
			& g_op_tab[op_code].type_arr[2])
		valid_count += 1;
	return (g_op_tab[op_code].nbr_arg == valid_count);
}
