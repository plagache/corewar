/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 11:57:34 by nabboufe          #+#    #+#             */
/*   Updated: 2020/06/19 23:47:54 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/disassemble.h"
#include <fcntl.h>

static int		error_management(int truth, char *filename, uint8_t *content)
{
	if (truth == 1)
		write(1, "usage: ./disassembler <file.cor>\n", 34);
	else if (truth == 2)
		write(1, "Error: could not create/open file.\n", 36);
	else if (truth == 3)
		write(1, "Error: bad file format (bad magic number)", 42);
	else if (truth == 4)
		ft_printf("Error: bad file extension, %s must be a <*.cor> file\n",
			filename);
	else if (truth == 5)
		write(1, "Error: given .cor file is too large", 36);
	else if (truth == 6)
		write(1, "Error: given .cor file is too small", 36);
	if (content)
		free(content);
	return (0);
}

static char		*is_cor(char *filename)
{
	int		index;
	char	*asm_file;

	index = ft_strlen(filename) - 1;
	if (index < 4)
		return (NULL);
	if (filename[index] != 'r' || filename[index - 1] != 'o'
			|| filename[index - 2] != 'c' || filename[index - 3] != '.')
		return (NULL);
	asm_file = ft_strdup(filename, 0);
	asm_file[index] = 's';
	asm_file[index - 1] = 'i';
	asm_file[index - 2] = 'd';
	return (asm_file);
}

static int		copy_file(t_uint8file file, t_corefile *core_file)
{
	ft_memcpy(&core_file->header, file.content, sizeof(t_header));
	core_file->header.magic = ft_4byteswap(core_file->header.magic);
	if (core_file->header.magic != COREWAR_EXEC_MAGIC)
		return (error_management(3, NULL, file.content));
	core_file->header.prog_size = ft_4byteswap(core_file->header.prog_size);
	if (core_file->header.prog_size != file.length - HEADER_SIZE)
	{
		ft_printf("Error: file is corrupt, claimed size: %d, actual: %d.\n",
			core_file->header.prog_size, file.length - HEADER_SIZE);
		free(file.content);
		return (0);
	}
	ft_memcpy(core_file->champ, file.content + sizeof(t_header),
		core_file->header.prog_size);
	core_file->header.prog_name[PROG_NAME_LENGTH] = '\0';
	core_file->header.comment[COMMENT_LENGTH] = '\0';
	return (1);
}

static int		load_file(char *fp, t_corefile *core_file)
{
	t_uint8file		file;

	if (!read_file(fp, &file))
		return (error_management(2, fp, NULL));
	if (((int)file.length) - HEADER_SIZE > CHAMP_MAX_SIZE)
		return (error_management(5, NULL, file.content));
	if (HEADER_SIZE >= file.length)
		return (error_management(6, NULL, file.content));
	if (!copy_file(file, core_file))
		return (0);
	free(file.content);
	return (1);
}

int				main(int argc, char **argv)
{
	char			*filename;
	t_corefile		core_file;

	if (argc != 2)
		return (error_management(1, NULL, NULL));
	if (!(filename = is_cor(argv[1])))
		return (error_management(4, argv[1], NULL));
	if ((core_file.fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644)) < 0)
	{
		free(filename);
		return (error_management(2, NULL, NULL));
	}
	free(filename);
	if (!load_file(argv[1], &core_file))
		return (0);
	w_header(&core_file);
	core_file.index = 0;
	while (core_file.header.prog_size > core_file.index)
		core_file.index += w_program(&core_file);
	filename = is_cor(argv[1]);
	ft_printf("Writing file in : %s\n", filename);
	free(filename);
	close(core_file.fd);
	return (0);
}
