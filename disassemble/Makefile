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

DECHET		=		*.dSYM

all			:		$(LIBFT_A) $(NAME)

$(LIBFT_A)	:		
	@make -C libft/ all clean >/dev/null
	@echo "libft compilation is done !\n"
	@mv libft/libft.a .

$(NAME)		:		$(OBJ) $(LIBFT_A)
	$(CC) $(CFLAGS) $(LIBFT_A) $(OBJ) $(INCLUDES) -o $(NAME)
	@rm -rf $(DECHET)

clean		:
	@rm -rf $(OBJ) $(DECHET)
	@echo "clean completed !"

fclean		:		clean
	@rm -rf $(NAME) $(LIBFT_A) $(DECHET) &>/dev/null
	@echo "fclean completed !\n"

re			:		fclean all

.PHONY		:		fclean all