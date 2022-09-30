/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:49:23 by nkim              #+#    #+#             */
/*   Updated: 2022/09/30 12:59:43 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "error.h"
#include "libft.h"
#include "parse.h"

static void	count_player(char *line, int *player_cnt)
{
	int		col;

	col = 0;
	while (line[col])
	{
		if (ft_strchr("NSEW", line[col]))
		{
			(*player_cnt)++;
			if (*player_cnt != 1)
				throw_error("InvalidMapError : too many player exist");
		}
		col++;
	}
}

void	valid_map(t_game *game)
{
	t_map_info	*map_info;
	char		*line;
	int			row;
	int			player_cnt;

	map_info = &game->map_info;
	row = 0;
	player_cnt = 0;
	while (row < map_info->height)
	{
		line = map_info->map[row];
		count_player(line, &player_cnt);
		valid_edge_wall(line, map_info->height, row);
		valid_inner_wall(line, map_info->map, map_info->height, row);
		row++;
	}
	if (player_cnt != 1)
		throw_error("InvalidMapError : player must exist only one");
}
