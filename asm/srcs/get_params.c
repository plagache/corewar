/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <alagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 19:24:10 by plagache          #+#    #+#             */
/*   Updated: 2020/06/07 07:45:21 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "asm.h"
#include "op.h"
#include "ft_printf.h"
#include "libft.h"
#include "manage_error.h"

/*
** procedure
** ac = 1 >> usage
** ac > 1 >> set file name from av / set option
** try open / set fd
*/

static	int		get_fd(t_file *file)
{
	file->fd = open(file->name, O_RDONLY);
	if (file->fd < 0)
		return (FAILURE);
	return (SUCCESS);
}

static	void	get_option(int ac, char **av, t_file *file)
{
	int counter;

	counter = ac;
	file->option = 0;
	while (--counter > 0)
	{
		if ((file->option & OPTION_A) == 0 && ft_strcmp(av[counter], "-a") == 0)
			file->option ^= OPTION_A;
	}
}

static	int		get_name(int ac, char **av, t_file *file)
{
	int counter;

	counter = ac;
	while (--counter > 0)
	{
		if (ft_strcmp(av[counter], "-a") != 0)
		{
			file->name = av[counter];
			return (SUCCESS);
		}
	}
	errno = ENOENT;
	return (FAILURE);
}

int				get_params(int ac, char **av, t_file *file)
{
	if (ac == 1)
	{
		ft_dprintf(STDERR_FILENO, "Usage: ./asm [-a] <sourcefile.s>\n	-a : "
			"Instead ofcreating a .cor file, outputs a stripped and annotated "
			"version of the code to the standard output\n");
		return (FAILURE);
	}
	ft_memset(file, 0, sizeof(t_file));
	if (get_name(ac, av, file) == FAILURE)
	{
		perror("get_name");
		return (FAILURE);
	}
	get_option(ac, av, file);
	if (get_fd(file) == FAILURE)
	{
		perror("open");
		return (FAILURE);
	}
	return (SUCCESS);
}
