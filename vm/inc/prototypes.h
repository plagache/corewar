/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <alagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 10:42:03 by agardina          #+#    #+#             */
/*   Updated: 2020/06/15 13:03:28 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H

# define PROTOTYPES_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdint.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"
# include "op.h"
# include "structs.h"
# include "defines.h"

/*
** A supprimer
*/

# include <stdio.h>

/*
** Parsing
*/

void		check_magic_header(uint32_t fd, t_data *data);
void		ft_read(int ac, char **av, t_data *data);
void		get_flags(int ac, char **av, t_data *data, uint32_t *i);
void		get_player_info(char *path, t_data *data, uint32_t player_num);
uint32_t	get_player_num(char **av, t_data *data, uint32_t *i);
void		get_players(int ac, char **av, t_data *data, uint32_t *i);
void		skip_null_bytes(t_data *data, uint32_t fd);

/*
** Error management
*/

void		deal_error(t_data *data, char *to_display, int code);

/*
** Carriages
*/

void		add_head_carriage(t_data *data);
t_carriage	*delete_one_carriage(t_data *data, t_carriage *current);
void		delete_all_carriages(t_data *data);

/*
** Delete / free
*/

void		free_data(t_data *data);

/*
** Cycles
*/

void		do_cycles(t_data *data);
int32_t		do_ope(int32_t opcode, t_data *data, t_carriage *current);

/*
** Dump
*/

void		dump_memory(t_data *data);

/*
** Preparation
*/

void		init_data(t_data *data);
void		prepare_arena(t_data *data);
void		prepare_carriages(t_data *data);

/*
** Utils
*/

uint32_t	get_from_ram(t_data *data, int32_t pos, int8_t len);
int32_t		get_pos(int32_t res);
void		write_in_ram(t_data *data, int32_t start, int32_t nb);

/*
** Announce
*/

void		announce_players(t_data *data);
void		announce_winner(t_data *data);

/*
** Ocp
*/

t_bool		check_ocp(t_data *data, t_carriage *current, t_ope *op);
void		get_ocp(t_data *data, t_carriage *current, t_ope *op);
t_bool		store_arg(t_data *data, t_carriage *current, t_ope *op,
	int8_t arg_type);

/*
**	Operations
*/

typedef int32_t	(*t_opee) (t_data *, t_carriage *);

int32_t		op_live(t_data *data, t_carriage *current);
int32_t		op_ld(t_data *data, t_carriage *current);
int32_t		op_st(t_data *data, t_carriage *current);
int32_t		op_add(t_data *data, t_carriage *current);
int32_t		op_sub(t_data *data, t_carriage *current);
int32_t		op_and(t_data *data, t_carriage *current);
int32_t		op_or(t_data *data, t_carriage *current);
int32_t		op_xor(t_data *data, t_carriage *current);
int32_t		op_zjmp(t_data *data, t_carriage *current);
int32_t		op_ldi(t_data *data, t_carriage *current);
int32_t		op_sti(t_data *data, t_carriage *current);
int32_t		op_fork(t_data *data, t_carriage *current);
int32_t		op_lld(t_data *data, t_carriage *current);
int32_t		op_lldi(t_data *data, t_carriage *current);
int32_t		op_lfork(t_data *data, t_carriage *current);
int32_t		op_aff(t_data *data, t_carriage *current);

#endif
