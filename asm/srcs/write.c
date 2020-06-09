/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <alagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 19:25:24 by plagache          #+#    #+#             */
/*   Updated: 2020/06/09 23:29:39 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "asm.h"
#include "libft.h"
#include "ft_printf.h"

/*
** get_name strip ".s" and add "cor" to create the output  filename
*/

static int	create_fd(t_file *file)
{
	int		fd;
	size_t	len;

	len = ft_strlen(file->name);
	if (file->name[len - 1] == 's' && file->name[len - 2] == '.')
	{
		file->file_name = ft_strnew(len + 2);
		if (file->file_name == NULL)
			return (FAILURE);
		ft_strncpy(file->file_name, file->name, len - 2);
		ft_strcpy(file->file_name + len - 2, ".cor");
	}
	else if ((file->file_name = ft_strjoin(file->name, ".cor")) == NULL)
		return (FAILURE);
	fd = open(file->file_name, O_CREAT | O_TRUNC | O_WRONLY,
			S_IRWXU | S_IRWXG | S_IRWXO);
	if (fd == -1)
		return (FAILURE);
	ft_printf(OUTPUT_STR, file->file_name);
	free(file->file_name);
	return (fd);
}

static void	reverse_write(void *to_write, int fd)
{
	char	arr[4];
	int		iterator;

	iterator = -1;
	while (++iterator < 4)
		arr[iterator] = ((char*)to_write)[3 - iterator];
	write(fd, &arr, 4);
}

static void	write_header(t_header *header, int fd)
{
	unsigned int	padding;

	padding = 0;
	reverse_write(&(header->magic), fd);
	write(fd, &(header->prog_name), PROG_NAME_LENGTH);
	reverse_write(&padding, fd);
	reverse_write(&(header->prog_size), fd);
	write(fd, &(header->comment), COMMENT_LENGTH);
	reverse_write(&padding, fd);
}

/*
** 2) write isntructions:
** char	instruction[1 + 1 + 4 + 4 + 4] = 14
** param(s)
** write (fd, &instruction, op->size);
*/

static void	write_instruction(t_cor *cor, int fd)
{
	char	instruction[14];
	int		iterator;
	int		arg;
	size_t	size;

	ft_memset(&(instruction), '\0', 14);
	instruction[0] = cor->op->op_code;
	iterator = 1;
	if (cor->op->nbr_arg > 1 || cor->op->op_code == 16)
		instruction[iterator++] = (cor->op->op_code == 16 ? AFF_OCP : cor->ocp);
	arg = 0;
	while (iterator != (int)cor->size)
	{
		size = what_size(cor->op->direct_size, cor->ocp, arg);
		ft_memcpy(&(instruction[iterator]), &(cor->val[arg][4 - size]), size);
		iterator += size;
		arg++;
	}
	write(fd, &instruction, cor->size);
}

int			write_infile(t_file *file)
{
	int	fd;
	int	iterator;

	if ((fd = create_fd(file)) == FAILURE)
		return (FAILURE);
	write_header(file->header, fd);
	iterator = -1;
	while ((file->cor + (++iterator))->line != NULL)
	{
		if (((file->cor) + iterator)->size > 0)
			write_instruction(file->cor + iterator, fd);
	}
	close(fd);
	return (SUCCESS);
}
