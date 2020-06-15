/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <alagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 10:26:55 by agardina          #+#    #+#             */
/*   Updated: 2020/06/15 13:01:18 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H

# define STRUCTS_H

typedef struct s_player		t_player;
typedef struct s_carriage	t_carriage;
typedef struct s_data		t_data;
typedef struct s_op			t_ope;
typedef struct s_vm			t_vm;
typedef enum e_bool			t_bool;

enum						e_bool
{
	false,
	true
};

struct						s_player
{
	uint32_t				code_size;
	unsigned char			name[PROG_NAME_LENGTH + 1];
	unsigned char			comment[COMMENT_LENGTH + 1];
	uint8_t					num;
	int8_t					code[CHAMP_MAX_SIZE];
	char					padding[7];
};

struct						s_carriage
{
	t_carriage				*previous;
	t_carriage				*next;
	int32_t					last_live;
	int32_t					cycles_to_wait;
	int32_t					pos;
	int32_t					bytes_to_jump;
	int32_t					reg[REG_NUMBER];
	t_bool					carry;
	int8_t					opcode;
	uint8_t					num;
	char					padding[2];
};

struct						s_vm
{
	uint8_t					arena[MEM_SIZE];
	uint32_t				nb_process;
	int						nb_cycles;
	int						cycles_since_last_check;
	int						last_player_live;
	int						nb_live;
	int						cycle_to_die;
	int						nb_checks;
	int						dump;
	int						cycle_to_dump;
	uint8_t					nb_players;
	char					padding[7];
};

struct						s_op
{
	int32_t					arg[3];
	int8_t					ocp;
	uint8_t					nb_arg;
	int8_t					dir_size;
	int8_t					nb_arg_stored;
	t_bool					idx_mod;
	char					padding[4];
};

struct						s_data
{
	t_vm					vm;
	t_player				players[MAX_PLAYERS];
	char					padding[4];
	t_carriage				*carriages;
};

#endif
