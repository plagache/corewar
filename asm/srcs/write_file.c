/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <alagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 07:36:27 by alagache          #+#    #+#             */
/*   Updated: 2020/06/15 15:20:00 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "asm.h"
#include "libft.h"

int		write_file(t_file *file)
{
	if (correct_arr(file->cor) == FAILURE
		|| write_infile(file) == FAILURE)
	{
		free(file->cor);
		free_arr((void**)file->lines);
		free(file->content);
		free(file->header_str);
		return (FAILURE);
	}
	free_arr((void**)file->lines);
	free(file->content);
	free(file->header_str);
	free(file->cor);
	return (SUCCESS);
}

void	write_stdout(t_file *file)
{
	if (correct_arr(file->cor) == FAILURE)
	{
		free_arr((void**)file->lines);
		free(file->content);
		free(file->header_str);
		free(file->cor);
	}
	print_stdout(file);
	free_arr((void**)file->lines);
	free(file->content);
	free(file->header_str);
	free(file->cor);
}

int		write_to(t_file *file)
{
	if (file->option != 0)
	{
		write_stdout(file);
		return (SUCCESS);
	}
	if (write_file(file) == FAILURE)
		return (FAILURE);
	return (SUCCESS);
}
