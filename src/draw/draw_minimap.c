#include "cub3D.h"
#include "draw.h"
#include "util.h"
#include <stdio.h>

void	draw_dir_line(t_state *state, int block, t_gl *gl)
{
	t_point	sp;
	t_point	ep;
	int		dist;

	dist = 20;
	sp.x = block * state->pos.x;
	sp.y = block * state->pos.y;
	ep.x = dist * state->dir.x + sp.x;
	ep.y = dist * state->dir.y + sp.y;
	draw_line(&sp, &ep, gl);
	return ;
}

// size : 3 (3x3 pixel)
void	draw_minimap_player(t_game *game, int size)
{
	int	i;
	int	j;

	i = 0;
	// printf("(posX, posY) : (%lf, %lf)\n", game->state.pos.x,
	// game->state.pos.y);
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			mlx_pixel_put(game->gl.mlx_ptr, game->gl.win_ptr, game->state.pos.x
					* game->minimap_info.b_size + i - 1, game->state.pos.y
					* game->minimap_info.b_size + j - 1, 0xffff00);
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
				ft_put_img(&game->gl, game->minimap_info.wall, col
						* game->minimap_info.b_size, row
						* game->minimap_info.b_size);
			else
				ft_put_img(&game->gl, game->minimap_info.space, col
						* game->minimap_info.b_size, row
						* game->minimap_info.b_size);
			col++;
		}
		while (col < map_info.width)
		{
			ft_put_img(&game->gl, game->minimap_info.space, col
					* game->minimap_info.b_size, row
					* game->minimap_info.b_size);
			col++;
		}
		row++;
	}
}