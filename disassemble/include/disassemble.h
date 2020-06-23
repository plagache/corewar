/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   disassemble.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/16 11:30:25 by nabboufe          #+#    #+#             */
/*   Updated: 2020/06/19 23:31:11 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISASSEMBLE_H
# define DISASSEMBLE_H

# include "op.h"
# include "../libft/includes/libft.h"
# include <stdint.h>

# define NB_OF_INSTRUCTION 16

typedef struct		s_op
{
	char			*keyword;
	char			nbr_arg;
	t_arg_type		type_arr[3];
	char			op_code;
	short			cycle_time;
	char			*name_description;
	char			carry;
	char			direct_size;
}					t_op;

typedef struct		s_corefile
{
	t_header		header;
	uint8_t			champ[CHAMP_MAX_SIZE];
	unsigned int	index;
	int				fd;
}					t_corefile;

typedef struct		s_uint8file
{
	uint8_t			*content;
	unsigned		capacity;
	unsigned		length;
	unsigned		width;
}					t_uint8file;

extern t_op			g_op_tab[NB_OF_INSTRUCTION + 1];

void				uint8file_init(t_uint8file *file, unsigned int size);
void				uint8file_resize(t_uint8file *file, unsigned size);
int					read_file(const char *filepath, t_uint8file *file);
void				w_header(t_corefile *file);
unsigned int		w_program(t_corefile *file);
int					check_type(uint8_t *champ, unsigned int pc);
unsigned int		w_param(unsigned int type, uint8_t op_code,
						t_corefile *file);

#endif
