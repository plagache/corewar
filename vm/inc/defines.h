/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <alagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:39:36 by agardina          #+#    #+#             */
/*   Updated: 2020/06/10 18:33:20 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H

# define DEFINES_H

# define SUCCESS 0
# define FAILURE -1

# define USAGE_STR1 "USAGE:\n./corewar (-d [nb] -dump [nb]) (-n [1 - 4]) "
# define USAGE_STR2 "file1.cor ... (-n [1 - 4]) file4.cor\n"
# define DUMP_USAGE "-d [nb] & -dump [nb] dumps memory at the cycle nb"
# define DUMP_USAGE2 "-d dumps on 64 bytes | -dump dumps on 32 bytes"
# define NBR_USAGE "-n [1 - 4] file.cor assigns the number to the player"
# define PARENTHESIS "Arguments in parenthesis are optional"
# define SEPARATOR "############################"
# define USAGE 1
# define NO_USAGE 0

# define TOO_FEW_ARG "Too few argument, check out usage"

# define D_FLAG		1
# define DUMP_FLAG	2
# define NBR_CHARSET	"+-123456789"
# define NO_NBR_ARGUMENT "Please check the arguments"

# define TOO_MANY_CHAMP "Too many champions"
# define PLAYER_NUM_ERR "Champion must have a number between 1 and 4"
# define BAD_FILE_NAME "Champion file are as follows (name.cor)"
# define CODE_SIZE "Code size must be between 1 and 682 bytes"

# define SMALL_DIR	2
# define BIG_DIR	4

#endif
