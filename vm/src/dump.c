/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <alagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 13:29:21 by alagache          #+#    #+#             */
/*   Updated: 2020/06/10 09:49:35 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	print_line(size_t address, char mem[64], size_t size)
{
	int	iterator;

	iterator = -1;
	if (address == 0)
		ft_printf("0x");
	ft_printf("%#.4x : ", (unsigned int)address);
	while (++iterator < (int)size)
			ft_printf("%.2x ", (unsigned char)mem[iterator]);
	ft_printf("\n");
}

void	dump_on(size_t size, uint8_t arena[MEM_SIZE])
{
	char	mem[64];
	size_t	iterator;

	iterator = 0;
	while (iterator != MEM_SIZE)
	{
		ft_memcpy(mem, arena + iterator, size);
		print_line(iterator, mem, size);
		iterator += size;
	}
}

void	dump_memory(t_data *data)
{
	if (data->vm.dump == DUMP_FLAG)
		dump_on(32, data->vm.arena);
	if (data->vm.dump == D_FLAG)
		dump_on(64, data->vm.arena);
}
