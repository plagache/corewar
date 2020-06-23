/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nabboufe <nabboufe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 23:10:08 by nabboufe          #+#    #+#             */
/*   Updated: 2020/06/23 14:44:30 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdint.h>
# include "math.h"
# include "get_next_line.h"
# include "ft_printf.h"

typedef struct		s_list_p
{
	struct s_list_p	*next;
	void			*data;
}					t_list_p;

typedef struct		s_begin
{
	t_list_p		*first_elem;
	t_list_p		*list;
}					t_begin;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

char				*ft_s_swap(char *s, char c, unsigned int n);
int					ft_ishere(const char *haystack, const char *needle);
uint32_t			ft_4byteswap(const uint32_t u32);
uint16_t			ft_2byteswap(const uint16_t byte);
int					ft_strchar(char *str, char occurency);
int					ft_chrlen(const char *s, char occurency);
int					ft_whereis(const char *str, char c, int n);
char				*ft_strnew(size_t size);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_bzero(void *s, size_t n);
void				ft_strdel(char **as);
char				*ft_strnstr(const char *str, const char *to_find, size_t n);
char				*ft_strstr(const char *str, const char *to_find);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
size_t				ft_strlen(const char *s);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
char				*ft_itoa(int n);
char				*ft_wstrrev(char *str, int i);
int					ft_atoi(const char *str);
void				ft_putnbr(int n);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				**ft_strsplit(char const *s, char c);
void				ft_create_elems_c(t_begin **begin, void *data);
t_begin				*ft_first_elem(void);
char				*ft_strtrim(char const *s);
char				*ft_strjoin(char *s1, char *s2, unsigned int truth);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strmap(char const *s, char (*f)(char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_striter(char *s, void (*f)(char *));
void				ft_strclr(char *s);
int					ft_toupper(int c);
int					ft_tolower(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
char				*ft_strdup(char *s1, int truth);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *n);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
char				*ft_nstrdup(char *str, int len, int truth);
char				*ft_itoa_base(int base, int number);
char				*ft_strrev(char *str);

#endif
