/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <alagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/07 07:36:27 by alagache          #+#    #+#             */
/*   Updated: 2020/06/07 07:41:54 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "op.h"
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
		return (FAILURE);
	}
	free(file->cor);
	free_arr((void**)file->lines);
	free(file->content);
	return (SUCCESS);
}
