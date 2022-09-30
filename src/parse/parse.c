/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:49:12 by nkim              #+#    #+#             */
/*   Updated: 2022/09/30 15:48:47 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "error.h"
#include "parse.h"
#include "libft.h"
#include <fcntl.h>

static void map_dup(t_map_info *map_info)
{
	int i;
	int j;
	int size;
	char **tmp;

	tmp = map_info->map;
	map_info->map = ft_calloc(map_info->height, sizeof(char *));
	if (!map_info->map)
		throw_error("Error : malloc error.");
	i = -1;
	while (++i < map_info->height) {
		map_info->map[i] = ft_calloc(map_info->width + 1, sizeof(char));
		j = -1;
		size = ft_strlen(tmp[i]);
		while (++j < size)
			map_info->map[i][j] = tmp[i][j];
		while (j < map_info->width)
		{
			map_info->map[i][j] = ' ';
			j++;
		}
		free(tmp[i]);
	}
	free(tmp);
}

void	parse(char *filename, t_game *game)
{
	int	fd;

	valid_extension(filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		throw_error("FileError : error when open file");
	parse_graphic_info(&game->graphic_info, fd, game->gl.mlx_ptr);
	parse_map_info(&game->map_info, fd);
	map_dup(&game->map_info);
	valid_map(game);
	parse_state(&game->state, &game->map_info);
	if (game->map_info.width < game->map_info.height)
		game->minimap_info.b_size = MINI_WIN_SIZE / game->map_info.height;
	else
		game->minimap_info.b_size = MINI_WIN_SIZE / game->map_info.width;
}
