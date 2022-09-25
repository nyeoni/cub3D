#include "cub3D.h"
#include "draw.h"
#include "util.h"
#include <stdio.h>

void	draw_dir_line(t_state *state, t_gl *gl)
{
	t_point	sp;
	t_point	ep;
	int		dist;

	dist = 10;
	printf("dir: (%lf, %lf)\n", state->dir.x, state->dir.y);
	printf("pos: (%lf, %lf)\n", state->pos.x, state->pos.y);
	sp.x = MINI_IMG_SIZE * state->pos.x;
	sp.y = MINI_IMG_SIZE * state->pos.y;
	ep.x = dist * state->dir.x + sp.x;
	ep.y = dist * state->dir.y + sp.y;
	printf("ep: (%lf, %lf)\n", ep.x, ep.y);
	printf("sp: (%lf, %lf)\n", sp.x, sp.y);
	draw_line(&sp, &ep, gl);
	return ;
}

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
			mlx_pixel_put(game->gl.mlx_ptr, game->gl.win_ptr, game->state.pos.x
					* MINI_IMG_SIZE + i, game->state.pos.y * MINI_IMG_SIZE + j,
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
				ft_put_img(&game->gl, game->minimap_info.wall, col
						* MINI_IMG_SIZE, row * MINI_IMG_SIZE);
			else
				ft_put_img(&game->gl, game->minimap_info.space, col
						* MINI_IMG_SIZE, row * MINI_IMG_SIZE);
			col++;
		}
		while (col < map_info.width)
		{
			ft_put_img(&game->gl, game->minimap_info.space, col * MINI_IMG_SIZE,
					row * MINI_IMG_SIZE);
			col++;
		}
		row++;
	}
}