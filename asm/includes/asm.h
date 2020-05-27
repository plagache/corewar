/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 18:58:51 by plagache          #+#    #+#             */
/*   Updated: 2020/05/27 16:53:44 by plagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"

# define SUCCESS 0
# define FAILURE -1
# define NO_DOT -1
# define NO_NAME -2
# define QUOTES -3
# define GARBAGE -4
# define TOO_LONG -5
# define OPTION_A 1
# define COMMENT 1
# define NAME 2
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

/*
** PARSE
*/

int		parse_file(t_file *file, t_header *header, t_cor *cor);
void	fill_header(char *str, t_header *header, int code);
int		whitespace(char *str, int len);
int		is_header_name(char *str);
int		is_header_comment(char *str);

#endif