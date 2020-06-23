NAME		=		disassembler

LIBFT_A		=		libft.a

INCLUDES	=		-Iinclude

SRCS		=		src/main.c				\
					src/op.c				\
					src/uint8file.c			\
					src/utils.c				\
					src/w_functions.c		\
					src/w_params.c


OBJ			=		$(SRCS:.c=.o)

CC			=		gcc

CFLAGS		=		-Wall -Wextra -Werror
CFLAGS		+=		-g3 -fsanitize=address,undefined

DECHET		=		*.dSYM

all			:		$(LIBFT_A) $(NAME)

$(LIBFT_A)	:		
	@make -C libft/ >/dev/null
	@echo "libft compilation is done !\n"
	@mv libft/libft.a .

#	Original compilation line
#	$(CC) $(CFLAGS) $(LIBFT_A) $(OBJ) $(INCLUDES) -o $(NAME)
$(NAME)		:		$(OBJ) $(LIBFT_A)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT_A) -o $(NAME)
	@rm -rf $(DECHET)

clean		:
	@rm -rf $(OBJ) $(DECHET)
	@echo "clean completed !"

fclean		:		clean
	@rm -rf $(NAME) $(LIBFT_A) $(DECHET) &>/dev/null
	@echo "fclean completed !\n"

re			:		fclean all

.PHONY		:		fclean all
