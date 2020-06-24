NAME		=		disassembler

LIBFT_A		=		libft/libft.a

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

all			:		$(NAME)

$(LIBFT_A)	:		
	$(MAKE) -C libft
	echo "libft compilation is done !"

#	Original compilation line
#	$(CC) $(CFLAGS) $(LIBFT_A) $(OBJ) $(INCLUDES) -o $(NAME)
$(NAME)		:		$(OBJ) $(LIBFT_A)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFT_A) -o $(NAME)
	rm -rf $(DECHET)
	echo "disassembler created"

clean		:
	rm -rf $(OBJ) $(DECHET)
	$(MAKE) -C libft/ clean
	echo "clean disassembler completed !"

fclean		:
	rm -rf $(NAME) $(LIBFT_A) $(DECHET) $(OBJ)
	$(MAKE) -C libft/ fclean
	echo "fclean disassembler completed !"

re			:
	$(MAKE) fclean
	$(MAKE) all

.PHONY		:		fclean clean re all $(LIBFT_A) $(NAME)
.SILENT		:
