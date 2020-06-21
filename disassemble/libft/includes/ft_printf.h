/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damboule <damboule@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 13:11:37 by damboule          #+#    #+#             */
/*   Updated: 2019/04/09 19:17:19 by nabboufe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H
# include "libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

char	*ft_short(char *nombre, va_list ap);
int		ft_count_num(char *numero);
int		ft_printf(const char *format, ...);
int		ft_conversion_pourcentage(char *args, char conversion);
int		ft_conversion_null(char *args);
int		ft_conversion_float(char *args, va_list ap, char conversion);
int		ft_conversion_hexa(char *args, va_list ap, char conversion);
char	*ft_hexa(unsigned long long int entier, char flag);
char	*ft_octale(unsigned long long entier);
int		ft_conversion_char(char *args, va_list ap, char conversion);
int		ft_conversion_octale(char *args, va_list ap, char conversion);
int		ft_conversion_int(char *args, va_list ap, char conversion);
char	*ft_moins(char *tab);
char	*ft_plus(char *tab);
int		ft_size(char *s1);
char	*ft_strdup_free(char *s1);

/*
** ft_tool_conversion :
*/

char	*ft_join_r_int(int largeur, char zero, char *string, int precision);
char	*ft_join_int(int largeur, char zero, char *numero, int precision);
int		ft_check_largeur(char *args, char *numero);
int		ft_check_precision(char *args, char *numero);
char	*ft_check_signe(char *args, char *nb_hexa);

/*
** ft_tool_char :
*/

char	*ft_join_reverse_char(int largeur, char zero, char *string);
char	*ft_join_char(int largeur, char zero, char *string);
int		ft_check_precision_char(char *args);
int		ft_check_largeur_char(char *args);

/*
** ft_tool_float :
*/

char	*ft_put_arrondie(int count, int a, char *nombre);
char	*ft_arrondie(char *nombre);
char	*ft_float(double f, int decimale);
int		ft_count_moins(char *nombre);
char	*ft_putmoins(char *nombre);

/*
** 	DOSSIER : ft_flag_conversion, ft_tool_cast et ft_tool_int :
**  Les cast:
*/

char	*ft_assign_type(char *nombre, char *args, va_list ap, char conversion);
char	*ft_unsigned_long(char *nombre, va_list ap, char conversion);
char	*ft_unsigned_long_long(char *nombre, va_list ap, char conversion);
char	*ft_unsigned_h(char *nombre, va_list ap, char conversion);
char	*ft_unsigned_h_h(char *nombre, va_list ap, char conversion);
char	*ft_long(char *nombre, va_list ap);
char	*ft_long_long(char *nombre, va_list ap);
char	*ft_int(char *nombre, va_list ap);
char	*ft_unsigned(char *nombre, va_list ap, char conversion);
char	*ft_join_int(int largeur, char zero, char *numero, int precision);

/*
** mettre dans lib :
*/

int		ft_atoi_unsigned(const char *str);
char	*ft_itoa_unsigned_long(unsigned long n);
char	*ft_itoa_unsigned_long_long(unsigned long long n);
char	*ft_itoa_long_long(long long int n);
char	*ft_itoa_long(long int n);
char	*ft_strrev(char *nombre);
void	ft_downcase(char *c);
void	ft_aff_char(char occur, int nb);
char	*ft_strjoin_free_c(char *s1, char s2);
char	*ft_itoa_unsigned(unsigned int n);
void	ft_putnbr_unsigned(unsigned int n);
char	*ft_strndup(char *string, int len, int truth);

#endif
