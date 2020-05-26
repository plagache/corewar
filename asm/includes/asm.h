/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 18:58:51 by plagache          #+#    #+#             */
/*   Updated: 2020/05/26 11:36:14 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"

# define SUCCESS -314
# define FAILURE -31415
# define USAGE "Usage: ./asm [-a] <sourcefile.s>\n	-a : Instead of creating \
a .cor file, outputs a stripped and annotated \
version of the code to the standard output\n"
# define NO_FILE "Can't read source file (null)\n"
# define ERROR_OPEN "Can't read source file %s\n"
# define OPTION_A 1
# define BUFF_SIZE 4096
# define WHITESPACE " \t"

typedef struct	s_cor
{
	int		ocp;
}				t_cor;

typedef struct  s_file
{
    int			fd;
	char		**lines;
    char		*content;
    char		*name;
    char		option;
	t_header	*header;
	t_cor		*cor;
}               t_file;

/*
** PARAMS
*/

int		get_params(int ac, char **av, t_file *file);

/*
** READ
*/

int			read_file(t_file *file);

#endif