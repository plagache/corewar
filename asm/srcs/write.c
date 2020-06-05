/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <alagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 19:25:24 by plagache          #+#    #+#             */
/*   Updated: 2020/06/05 07:04:46 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**
1) write header:
- execmagic 4 bytes reverse write with putcharfd
- name 128 bytes
- padding 4 bytes
- progsize 4 bytes reverse write with putcharfd
- comment 2048 bytes
- padding 4 bytes
2) write isntructions:
if (size > 0):
char	instruction[1 + 1 + 4 + 4 + 4] = 14

char[0] = OP_code
i = 1;
if (nb_arg >  1 || (OP_code == 16)
{
	char[i] = OCP	|| AFF_OCP
	i++;
}
param(s)


write (fd, &instruction, op->size);
**
*/
