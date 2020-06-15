/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <alagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 07:36:27 by alagache          #+#    #+#             */
/*   Updated: 2020/06/09 14:34:48 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "asm.h"
#include "libft.h"

int	write_file(t_file *file)
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
