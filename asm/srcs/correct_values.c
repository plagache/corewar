/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_values.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <alagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/05 05:58:32 by alagache          #+#    #+#             */
/*   Updated: 2020/06/05 06:49:38 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "op.h"
#include "asm.h"
#include "libft.h"
#include "ft_printf.h"
#include "manage_error.h"

/*
ABCD
CD AB
D C  B A
*/

/*
**
!! 0 <= reg value <= 99
for every arg:
	if nb_arg > 1:
	-	int	size(Direct_size, OCP, param_nb);
	else
		size - 1 - (op_code == 16 ? 1 : 0);
-	int	correct_value(int size, int value);
-	copy mem to byte array; (memcpy)
-	swap bytes;
RDY TO write;
**
*/
