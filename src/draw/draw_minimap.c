#include "cub3D.h"
#include "util.h"

void	draw_minimap_player(t_game *game, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			mlx_pixel_put(game->gl.mlx_ptr, game->gl.win_ptr,
					game->minimap_info.pos.x + i, game->minimap_info.pos.y + j,
					0xffff00);
			j++;
		}
		i++;
	}
}

void	draw_minimap_bg(t_game *game)
{
	t_map_info map_info;
	char *line;
	int row;
	int col;

	map_info = game->map_info;
	row = 0;
	while (row < map_info.height)
	{
		line = map_info.map[row];
		col = 0;
		while (line[col] && col < map_info.width)
		{
			if (line[col] == '1')
				ft_put_img(&game->gl, game->minimap_info.wall, col * BLOCK_SIZE,
						row * BLOCK_SIZE);
			else
				ft_put_img(&game->gl, game->minimap_info.space, col
						* BLOCK_SIZE, row * BLOCK_SIZE);
			col++;
		}
		while (col < map_info.width)
		{
			ft_put_img(&game->gl, game->minimap_info.space, col * BLOCK_SIZE,
					row * BLOCK_SIZE);
			col++;
		}
		row++;
	}
}