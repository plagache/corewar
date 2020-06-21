/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint8file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/18 15:20:12 by nabboufe          #+#    #+#             */
/*   Updated: 2020/06/19 23:24:22 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/disassemble.h"

void	uint8file_init(t_uint8file *file, unsigned int size)
{
	file->width = size;
	file->content = malloc(size * 8);
	file->capacity = 8;
	file->length = 0;
}

void	uint8file_resize(t_uint8file *file, unsigned int size)
{
	uint8_t		*new;

	if (size > file->length)
	{
		new = realloc(file->content, size * file->width);
		file->content = new;
		file->capacity = size;
	}
}
