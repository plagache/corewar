/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stdout.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <alagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/15 15:20:15 by alagache          #+#    #+#             */
/*   Updated: 2020/06/15 17:21:25 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "asm.h"
#include "libft.h"
#include "ft_printf.h"

static void	write_header(t_header *header)
{
	ft_printf("Program size : %i bytes\n", header->prog_size);
	ft_printf("Name : \"%s\"\n", header->prog_name);
	ft_printf("Comment : \"%s\"\n\n", header->comment);
}

static void write_label(t_cor *cor)
{
	ft_printf("%-4i       :    %s\n", cor->inc_size, cor->label);
}

static void octet_line(t_cor *cor)
{
	int	arg;
	int	size;
	int	iterator;

	ft_printf("\n%19s ","");
	if (cor->op->op_code == 16 || cor->op->nbr_arg > 1)
		ft_printf("%-3i %-5i ", cor->op->op_code, cor->ocp);
	else
		ft_printf("%-9i ", cor->op->op_code);
	arg = 0;
	while (arg < cor->op->nbr_arg)
	{
		size = what_size(cor->op->direct_size, cor->ocp, arg);
		iterator = 0;
		while (iterator < (int)size)
		{
			ft_printf("%-3u ", (unsigned char)cor->val[arg][iterator + 4 - size]);
			iterator++;
		}
		arg++;
		ft_printf("  ");
		while (iterator++ < 4)
			ft_printf("%4s", "");
	}
}

static void write_instruction(t_cor *cor)
{
	int	iterator;

	ft_printf("%-4i (%-3i) :        %-10s", cor->inc_size, cor->size,
		cor->op->keyword);
	iterator = -1;
	while (++iterator < cor->op->nbr_arg)
		ft_printf("%-18s", cor->params[iterator]);

	octet_line(cor);

	ft_printf("\n%19s ","");
	if (cor->op->op_code == 16 || cor->op->nbr_arg > 1)
		ft_printf("%-3i %-5i ", cor->op->op_code, cor->ocp);
	else
		ft_printf("%-9i ", cor->op->op_code);
	iterator = -1;
	while (++iterator < cor->op->nbr_arg)
		ft_printf("%-18i", cor->value[iterator]);

	ft_printf("\n\n");
}

int		print_stdout(t_file *file)
{
	int	iterator;

	ft_printf("Dumping annotated program on standard output\n");
	write_header(file->header);
	iterator = -1;
	while ((file->cor + (++iterator))->line != NULL)
	{
		if ((file->cor + iterator)->label != NULL)
			write_label(file->cor + iterator);
		if ((file->cor + iterator)->op != NULL)
			write_instruction(file->cor + iterator);
	}
	return (SUCCESS);
}
