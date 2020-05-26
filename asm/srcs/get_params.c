/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 19:24:10 by plagache          #+#    #+#             */
/*   Updated: 2020/05/26 10:24:01 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"
#include "ft_printf.h"
#include "libft.h"
#include <fcntl.h>

/*
** procedure
** ac = 1 >> usage
** ac > 1 >> set file name from av / set option
** try open / set fd
** 
*/
static	int		get_fd(t_file * file)
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
	return (FAILURE);
}

int		get_params(int ac, char **av, t_file *file)
{
	if (ac == 1)
	{
		ft_printf(USAGE);
		return (FAILURE);
	}
	ft_memset(file, 0, sizeof(t_file));
	if (get_name(ac, av, file) == FAILURE)
	{
		ft_printf(NO_FILE);
		return (FAILURE);
	}
	get_option(ac, av, file);
	if (get_fd(file) == FAILURE)
	{
		ft_printf(ERROR_OPEN, file->name);
		return (FAILURE);
	}
	return (SUCCESS);
}