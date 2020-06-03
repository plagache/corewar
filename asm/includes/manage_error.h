/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_error.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <alagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 15:03:26 by plagache          #+#    #+#             */
/*   Updated: 2020/06/03 23:36:20 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MANAGE_ERROR_H
# define MANAGE_ERROR_H

# include <stdio.h>
# include <errno.h>

# define USAGE1 "Usage: ./asm [-a] <sourcefile.s>\n	-a : Instead of creating "
# define USAGE2 "a .cor file, outputs a stripped and annotated version of "
# define USAGE3 "the code to the standard output\n"
# define NO_FILE "Can't read source file (null)\n"
# define ERROR_OPEN "Can't read source file %s\n"
# define SPLIT_MALLOC "ERROR: malloc failed during split process\n"
# define READ_MALLOC "ERROR: malloc failed during read process\n"
# define SYNTAX "Syntax error\n"
# define LONG_NAME "Champion name too long (Max Lenght %i)\n"
# define LONG_COMMENT "Champion comment too long (Max Lenght %i)\n"
# define ERR_QUOTES "Wrong number of quotes\n"
# define NON_EMPTY_LNE "Label error on line |%s|\n"
# define WRONG_LABEL "Wrong label found |%s|\n"
# define EMPTY_ARG "Empty argument found\n"
# define INVALID_TYPE "Invalid parameter %i type %s for instruction %s\n"
# define NOT_PARAM "Parameter number #%i not recognized for instruction %s\n"
# define WRONG_PARAM "Wrong parameter content #%i|%s| in instruction |%s|\n"
# define WS_HEADER "Error on line |%s|\n"

#endif
