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

static void	skip_null_bytes(t_data *data, uint32_t fd)
{
	char	null_bytes[4];
	int		ret;

	if ((ret = read(fd, null_bytes, 4)) < 4)
		deal_error(data, "");
	if (null_bytes[0] != 0 || null_bytes[1] != 0 || null_bytes[2] != 0
	|| null_bytes[3] != 0)
		deal_error(data, "");
}

static void	get_player_name(uint32_t fd, t_data *data, uint32_t player_num)
{
	int	ret;

	ret = read(fd, data->players[player_num - 1].name, PROG_NAME_LENGTH);
	if (ret < PROG_NAME_LENGTH)
		deal_error(data, "");
}

static void	get_player_code_size(uint32_t fd, t_data *data, uint32_t player_num)
{
	unsigned char	code_size[4];
	int				ret;

	if ((ret = read(fd, code_size, 4)) < 4)
		deal_error(data, "");
	data->players[player_num - 1].code_size = (code_size[0] << 24) +
	(code_size[1] << 16) + (code_size[2] << 8) + code_size[3];
}

static void	get_player_comment(uint32_t fd, t_data *data, uint32_t player_num)
{
	uint32_t ret;

	ret = read(fd, data->players[player_num - 1].comment, COMMENT_LENGTH);
	if (ret < COMMENT_LENGTH)
		deal_error(data, "");
}

static void	get_player_code(uint32_t fd, t_data *data, uint32_t player_num)
{
	int	ret;

	ret = read(fd, data->players[player_num - 1].code,
		data->players[player_num - 1].code_size);
	if (ret < (int)data->players[player_num - 1].code_size)
		deal_error(data, "");
}

static void	check_magic_header(uint32_t fd, t_data *data)
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

void		get_player_info(char *path, t_data *data, uint32_t player_num)
{
	int		ret;
	int		fd;
	char	end[2];

	if ((fd = open(path, O_RDONLY)) == -1)
		deal_error(data, "");
	check_magic_header(fd, data);
	get_player_name(fd, data, player_num);
	skip_null_bytes(data, fd);
	get_player_code_size(fd, data, player_num);
	get_player_comment(fd, data, player_num);
	skip_null_bytes(data, fd);
	get_player_code(fd, data, player_num);
	if ((ret = read(fd, end, 1)) != 0)
	{
		close(fd);
		deal_error(data, "");
	}
	close(fd);
}
