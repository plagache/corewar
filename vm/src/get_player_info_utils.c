/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_info_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alagache <alagache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 15:34:05 by agardina          #+#    #+#             */
/*   Updated: 2020/06/15 12:48:19 by alagache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	skip_null_bytes(t_data *data, uint32_t fd)
{
	char	null_bytes[4];
	int		ret;

	if ((ret = read(fd, null_bytes, 4)) < 4)
		deal_error(data, MISSING_PADDING, NO_USAGE);
	if (null_bytes[0] != 0 || null_bytes[1] != 0 || null_bytes[2] != 0
	|| null_bytes[3] != 0)
		deal_error(data, WRONG_PADDING, NO_USAGE);
}

void	check_magic_header(uint32_t fd, t_data *data)
{
	unsigned char	magic_header[4];
	int				ret;

	ft_bzero(magic_header, sizeof(char) * 4);
	if ((ret = read(fd, magic_header, 4)) < 4)
		deal_error(data, MISSING_MAGIC, NO_USAGE);
	if (magic_header[0] != ((COREWAR_EXEC_MAGIC >> 24) & 0xFF)
		|| magic_header[1] != ((COREWAR_EXEC_MAGIC >> 16) & 0xFF)
		|| magic_header[2] != ((COREWAR_EXEC_MAGIC >> 8) & 0xFF)
		|| magic_header[3] != (COREWAR_EXEC_MAGIC & 0xFF))
		deal_error(data, WRONG_MAGIC, NO_USAGE);
}
