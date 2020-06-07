/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <alagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 18:58:51 by plagache          #+#    #+#             */
/*   Updated: 2020/06/07 12:20:16 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "op.h"
# include "stddef.h"

# define SUCCESS 0
# define FAILURE -1
# define ERR_MALLOC -2
# define NO_DOT -1
# define NO_NAME -2
# define QUOTES -3
# define GARBAGE -4
# define TOO_LONG_NAME -5
# define TOO_LONG_COMMENT -5
# define OPTION_A 1
# define COMMENT 1
# define NAME 2
# define NOT_LABEL -2
# define NOT_OP -2
# define BUFF_SIZE 4096
# define WHITESPACE " \t"
# define PARAMS_CHAR "abcdefghijklmnopqrstuvwxyz_0123456789:%-"
# define SEP_CHARS "% ,"
# define AFF_OCP 40

typedef struct	s_cor
{
	char	*params[3];
	char	val[3][4];
	char	*line;
	char	*label;
	char	*op_str;
	t_op	*op;
	int		value[3];
	size_t	size;
	size_t	inc_size;
	short	ocp;
}				t_cor;

typedef struct	s_file
{
	t_header	*header;
	t_cor		*cor;
	char		**lines;
	char		*content;
	char		*name;
	int			fd;
	int			line;
	char		option;
}				t_file;

/*
** PARAMS
*/

int				get_params(int ac, char **av, t_file *file);

/*
** READ
*/

int				read_file(t_file *file);

/*
** PARSE
*/

int				parse_file(t_file *file, t_header *header);
int				whitespace(char *str, int len);
void			fill_header(char *str, t_file *file, int code, int line);
int				is_header_name(char *str);
int				is_header_comment(char *str);
int				parse_op(t_file *file);
int				set_label_op(t_cor *cor);
char			gen_ocp(t_cor *cor);
int				check_ocp(t_cor *cor);
int				set_params(t_cor *cor, t_header *header);
void			get_values(t_cor *cor);

/*
** WRITE
*/
int				write_file(t_file *file);
int				what_size(char direct_size, short ocp, int param_nb);
int				correct_arr(t_cor *cor);
int				write_infile(t_file *file);

#endif
