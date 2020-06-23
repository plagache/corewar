/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <alagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/08 15:39:36 by agardina          #+#    #+#             */
/*   Updated: 2020/06/11 13:15:24 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H

# define DEFINES_H

# define SUCCESS 0
# define FAILURE -1

# define USAGE_STR1 "USAGE:\n./corewar (-d [nb] -dump [nb]) (-v [nb]) (-a) "
# define USAGE_STR2 "(-n [1 - 4]) file1.cor ... (-n [1 - 4]) file4.cor\n"
# define DUMP_USAGE "-d [nb] or -dump [nb] dumps memory at the cycle nb"
# define DUMP_USAGE2 "-d dumps on 64 bytes | -dump dumps on 32 bytes"
# define VERBOSE_USAGE "-v [nb] : verbosity levels, can be added together to"
# define VERBOSE_USAGE2 "enable several"
# define VERBOSE_USAGE3 "\t- 0 : Show only essentials"
# define VERBOSE_USAGE4 "\t- 1 : Show lives"
# define VERBOSE_USAGE5 "\t- 2 : Show cycles"
# define VERBOSE_USAGE6 "\t- 4 : Show operations"
# define VERBOSE_USAGE7 "\t- 8 : Show deaths"
# define VERBOSE_USAGE8 "\t- 16 : Show PC movements (except for jumps)"
# define AFF_USAGE "-a prints output from \"aff\" (hidden by default)"
# define NBR_USAGE "-n [1 - 4] file.cor assigns the number to the player"
# define PARENTHESIS "Arguments in parenthesis are optional"
# define SEPARATOR "############################"
# define USAGE 1
# define NO_USAGE 0

# define TOO_FEW_ARG "Too few arguments, check out usage"

# define D_FLAG		1
# define DUMP_FLAG	2
# define NBR_CHARSET	"+-0123456789"
# define NO_NBR_ARGUMENT "Please check the arguments"

# define TOO_MANY_CHAMP "Too many champions"
# define PLAYER_NUM_ERR "Champion must have a number between 1 and 4"
# define BAD_FILE_NAME "Champion files are as follows (name.cor)"
# define CODE_SIZE "Code size must be between 1 and 682 bytes"

# define OPEN_FAILURE "Fail to open Champion"

# define INT_BOUND "Player number is out of boundary"
# define VERB_BOUND "Verbose number must be between 0 and 31"

# define MISSING_PADDING "Missing or incorrect format for padding"
# define MISSING_CODE_S "Missing or incorrect format for code size value"
# define MISSING_PROG_S "Missing or incorrect size for code"
# define MISSING_MAGIC "Missing or incorrect format for magic header"

# define WRONG_PADDING "Wrong value found in padding"
# define WRONG_MAGIC "Wrong value found in magic header"

# define T_L_PROG_NAME "Champion name exceed the acceptable lenght"
# define T_L_PROG_CMNT "Champion comment is too long"
# define T_L_FILE "File contains more bytes than expected"

# define SMALL_DIR	2
# define BIG_DIR	4

#endif
