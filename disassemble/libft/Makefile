NAME		=		libft.a

CC			=		gcc

CFLAGS		+=		-Wall -Werror -Wextra

LIB			=		ar rcs $(NAME) $(OBJ)

RANLIB		=		ranlib

WASTE		=		*/*.h.gch

INCLUDES	=		includes/libft.h                           \
					includes/get_next_line.h                   \
					includes/math.h                            \
					includes/ft_printf.h

SRC			=		math/n_matrix.c                            \
					math/nminit_to_zero.c                      \
					math/nminit_to_one.c                       \
					math/nminit_to_one_zero.c                  \
					math/print_nmatrix.c                       \
					ft_printf/ft_short.c                       \
					ft_printf/ft_conversion_char.c             \
					ft_printf/ft_conversion_float.c            \
					ft_printf/ft_conversion_hexa.c             \
					ft_printf/ft_conversion_int.c              \
					ft_printf/ft_conversion_null.c             \
					ft_printf/ft_conversion_octale.c           \
					ft_printf/ft_conversion_pourcentage.c      \
					ft_printf/ft_flag_conversion.c             \
					ft_printf/ft_itoa_1.c                      \
					ft_printf/ft_itoa_2.c                      \
					ft_printf/ft_printf.c                      \
					ft_printf/ft_tool_cast.c                   \
					ft_printf/ft_tool_char.c                   \
					ft_printf/ft_tool_conversion.c             \
					ft_printf/ft_tool_float.c                  \
					ft_printf/ft_tool_int.c                    \
					ft_printf/ft_utilities.c                   \
					ft_printf/ft_count_num.c                   \
					strings/ft_byteswap.c					   \
					strings/ft_s_swap.c                        \
					strings/ft_strchar.c                       \
					strings/ft_itoa.c                          \
					strings/ft_ishere.c                        \
					strings/ft_chrlen.c                        \
					strings/ft_strlen.c                        \
					strings/ft_putchar.c                       \
					strings/ft_putstr.c                        \
					strings/ft_wstrrev.c                       \
					strings/ft_putnbr.c                        \
					strings/ft_atoi.c                          \
					strings/ft_putstr_fd.c                     \
					strings/ft_putendl.c                       \
					strings/ft_putchar_fd.c                    \
					strings/ft_putendl_fd.c                    \
					strings/ft_putnbr_fd.c                     \
					strings/ft_memalloc.c                      \
					strings/ft_memdel.c                        \
					strings/ft_strsplit.c                      \
					strings/ft_strcmp.c                        \
					strings/ft_strncmp.c                       \
					strings/ft_strstr.c                        \
					strings/ft_strnstr.c                       \
					strings/ft_strtrim.c                       \
					strings/ft_create_elems_c.c                \
					strings/ft_first_elem.c                    \
					strings/ft_putstr_list.c                   \
					strings/ft_strjoin.c                       \
					strings/ft_strdel.c                        \
					strings/ft_bzero.c                         \
					strings/ft_memset.c                        \
					strings/ft_strnew.c                        \
					strings/ft_strsub.c                        \
					strings/ft_strnequ.c                       \
					strings/ft_strequ.c                        \
					strings/ft_strmapi.c                       \
					strings/ft_strmap.c                        \
					strings/ft_striteri.c                      \
					strings/ft_striter.c                       \
					strings/ft_strclr.c                        \
					strings/ft_toupper.c                       \
					strings/ft_tolower.c                       \
					strings/ft_isascii.c                       \
					strings/ft_isprint.c                       \
					strings/ft_isalnum.c                       \
					strings/ft_isalpha.c                       \
					strings/ft_isdigit.c                       \
					strings/ft_strdup.c                        \
					strings/ft_strncpy.c                       \
					strings/ft_strcpy.c                        \
					strings/ft_strcat.c                        \
					strings/ft_strncat.c                       \
					strings/ft_memcpy.c                        \
					strings/ft_memccpy.c                       \
					strings/ft_strchr.c                        \
					strings/ft_strrchr.c                       \
					strings/ft_memmove.c                       \
					strings/ft_memchr.c                        \
					strings/ft_memcmp.c                        \
					strings/ft_strlcat.c                       \
					strings/ft_lstnew.c                        \
					strings/ft_lstdelone.c                     \
					strings/ft_lstdel.c                        \
					strings/ft_lstadd.c                        \
					strings/ft_lstiter.c                       \
					strings/ft_lstmap.c                        \
					strings/ft_nstrdup.c                       \
					strings/ft_whereis.c                       \
					strings/get_next_line.c                    \
					strings/ft_strrev.c

OBJ			=		$(SRC:.c=.o)

all			:		$(NAME)

$(NAME)		:		$(OBJ)
	$(LIB)

clean		:
	$(RM) $(OBJ) $(WASTE)

fclean		:
	$(MAKE) clean
	$(RM) $(NAME)

re			:
	$(MAKE) fclean
	$(MAKE) all

.PHONY		: all clean fclean re $(NAME)
.SILENT		:
