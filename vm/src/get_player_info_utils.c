/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agardina <agardina@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/03 15:34:05 by agardina          #+#    #+#             */
/*   Updated: 2020/06/03 15:34:05 by agardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prototypes.h"

void	skip_null_bytes(t_data *data, uint32_t fd)
{
	char	null_bytes[4];
	int		ret;

	if ((ret = read(fd, null_bytes, 4)) < 4)
		deal_error(data, "");
	if (null_bytes[0] != 0 || null_bytes[1] != 0 || null_bytes[2] != 0
	|| null_bytes[3] != 0)
		deal_error(data, "");
}

void	check_magic_header(uint32_t fd, t_data *data)
{
	unsigned char	magic_header[4];
	int				header;
	int				ret;

	header = 0;
	ft_bzero(magic_header, sizeof(char) * 4);
	if ((ret = read(fd, magic_header, 4)) < 4)
		deal_error(data, "");
	if ((header = (magic_header[0] << 24) + (magic_header[1] << 16)
	+ (magic_header[2] << 8) + magic_header[3]) != COREWAR_EXEC_MAGIC)
		deal_error(data, "");
}
