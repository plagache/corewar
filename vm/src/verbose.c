/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verbose.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 12:50:21 by agardina          #+#    #+#             */
/*   Updated: 2020/06/22 12:50:44 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void		print_cycle(t_data *data)
{
	ft_printf("It is now cycle %u\n", data->vm.nb_cycles);
}

static void	print_zeros(uint32_t nb)
{
	if (nb <= 0x0F)
		ft_printf("000");
	else if (nb <= 0xFF)
		ft_printf("00");
	else if (nb <= 0xFFF)
		ft_printf("0");
}

void		print_pc_movements(t_data *data, t_carriage *current)
{
	int32_t	i;

	if (current->opcode == 9)
		return ;
	i = 0;
	ft_printf("ADV %d (0x", current->bytes_to_jump);
	print_zeros(current->pos);
	ft_printf("%x -> 0x", current->pos);
	print_zeros(current->pos + current->bytes_to_jump);
	ft_printf("%x)", current->pos + current->bytes_to_jump);
	while (i < current->bytes_to_jump)
	{
		ft_printf(" ");
		if (data->vm.arena[get_pos(current->pos + i)] <= 15)
			ft_printf("0");
		ft_printf("%x", data->vm.arena[get_pos(current->pos + i)]);
		i++;
	}
	ft_printf("\n");
}

void		print_proc_and_ft(t_carriage *current)
{
	static const char *functions_name[] = {"live", "ld", "st", "add", "sub",
		"and", "or", "xor", "zjmp", "ldi", "sti", "fork", "lld", "lldi",
		"lfork", "aff"};

	if (current->opcode == 16)
		return ;
	if (current->num < 10)
		ft_printf("P    %u", current->num);
	else
		ft_printf("P   %u", current->num);
	ft_printf(" | %s ", functions_name[current->opcode - 1]);
}
