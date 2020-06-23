NAME = corewar

CC = clang
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -Wpadded -fsanitize=address,undefined -g3

SRC_DIR = src/
SRC_FILES = announce_players.c \
				announce_winner.c \
				deal_error.c \
				delete_carriage.c \
				do_cycles.c \
				do_ope.c \
				dump.c \
				free_data.c \
				ft_read.c \
				get_flags.c \
				get_player_info.c \
				get_player_info_utils.c \
				get_player_num.c \
				get_players.c \
				init_data.c \
				main.c \
				ocp.c \
				prepare_arena.c \
				prepare_carriages.c \
				store_arg.c \
				utils.c \
				verbose.c \
				operations/op_add_sub.c \
				operations/op_aff.c \
				operations/op_and_or_xor.c \
				operations/op_fork_lfork.c \
				operations/op_ld_lld.c \
				operations/op_ldi_lldi.c \
				operations/op_live.c \
				operations/op_st.c \
				operations/op_sti.c \
				operations/op_zjmp.c
SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ_DIR = obj/
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ = $(addprefix $(OBJ_DIR), $(OBJ_FILES))

INC_DIR = inc/
INC_FILES = defines.h \
				op.h \
				prototypes.h \
				structs.h
INC = $(addprefix $(INC_DIR), $(INC_FILES))

#USING alagache libft in submodule to have ft_printf
LIB_DIR = ../libft/
LIB = $(LIB_DIR)libft.a
LIB_INC = $(LIB_DIR)includes/
LIB_FLAGS = -L $(LIB_DIR) -lft

INCLUDES = -I $(INC_DIR)
INCLUDES += -I $(LIB_INC)

all: $(OBJ_DIR) $(NAME)

#LIB_FLAGS on linux are after objects to compile
#This next line is mac compliation
#	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIB_FLAGS) -o $@
$(NAME): $(LIB) $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIB_FLAGS) -o $@
	# $(CC) $(CFLAGS) $(INCLUDES) $(OBJ) -o $@ $(LIB_FLAGS)
	echo "\033[32mmake vm done\033[0m"

$(LIB): FORCE
	$(MAKE) -C $(LIB_DIR)

$(OBJ_DIR):
	mkdir $@
	mkdir $@/operations

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INC)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	echo "$@ [\033[32mOK\033[0m]"

clean:
	$(MAKE) -C $(LIB_DIR) clean
	rm -rf $(OBJ_DIR)
	echo "\033[35mclean vm done\033[0m"

fclean:
	make -C $(LIB_DIR) fclean
	$(MAKE) clean
	rm -rf $(NAME)
	echo "\033[35mfclean vm done\033[0m"

re:
	$(MAKE) fclean
	$(MAKE) all

FORCE:

.PHONY: all clean fclean re FORCE
.SILENT:
