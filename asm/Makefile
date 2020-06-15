NAME = asm

SRC	=	op.c\
		asm.c\
		get_params.c\
		read.c\
		parse.c\
		parse_tools.c\
		parse_op_tool.c\
		set_label_op_params.c\
		param_tools.c\
		set_params.c\
		get_value.c\
		correct_values.c\
		write.c\
		print_stdout.c\
		write_file.c\

SRCS = $(addprefix srcs/,$(SRCS))

OBJECT = $(addprefix out/,$(SRC:.c=.o))

LIBDIR = ../libft

LIBA = $(LIBDIR)/libft.a

INC_FLAG = -I includes
INC_FLAG += -I $(LIBDIR)/includes

LIB_FLAG = -L $(LIBDIR) -lft

CFLAGS = -Wall -Wextra -Werror -g3
CFLAGS += -fsanitize=address,undefined -fno-omit-frame-pointer
#CFLAGS += -fsanitize=thread,undefined 
#CFLAGS += -fsanitize=memory,undefined

CC = clang
#CC = gcc

BLUE = "\\033[36m"
RED = "\\033[31m"
WHITE = "\\033[0m"
GREEN = "\\033[32m"
PURPLE = "\\033[35m"

LNECLR = "\\33[2K\\r"

all: $(NAME)

$(NAME): $(OBJECT)
	make -s -C $(LIBDIR)
#	$(CC) $(CFLAGS) -I includes -I $(LIBDIR)/includes -o $(NAME) $(OBJECT) $(LIBA)
	$(CC) $(CFLAGS) $(INC_FLAG) -o $(NAME) $(OBJECT) $(LIB_FLAG)
	printf "$(LNECLR)$(GREEN)make asm done$(WHITE)\n"

out/%.o: srcs/%.c includes/asm.h includes/op.h includes/manage_error.h
	mkdir -p out
	printf "$(LNECLR)$(NAME): $<"
#	$(CC) $(CFLAGS) -I includes -I $(LIBDIR)/includes -o $@ -c $<
	$(CC) $(CFLAGS) $(INC_FLAG) -o $@ -c $<

clean:
	$(RM) -rf out
	make -s -C $(LIBDIR) clean
	printf "$(PURPLE)clean asm done$(WHITE)\n"

fclean:
	$(RM) -rf out $(NAME)
	make -s -C $(LIBDIR) fclean
	printf "$(PURPLE)fclean asm done$(WHITE)\n"

re: fclean all

.PHONY: all fclean clean re FORCE

.SILENT: all fclean clean re FORCE $(NAME) $(OBJECT)

.NOTPARALLEL: re
