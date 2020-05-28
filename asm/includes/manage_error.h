/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_error.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plagache <plagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/27 15:03:26 by plagache          #+#    #+#             */
/*   Updated: 2020/05/29 00:31:46 by alagache         ###   ########.fr       */
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

#endif
