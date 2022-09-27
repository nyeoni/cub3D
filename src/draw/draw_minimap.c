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

void	draw_minimap_player(t_game *game)
{
	int	i;
	int	j;
	int	size;

	i = 0;
	size = 3;
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
	t_map_info	map_info;
	t_point		sp;
	char		*line;
	int			row;
	int			col;

	map_info = game->map_info;
	row = 0;
	while (row < map_info.height)
	{
		line = map_info.map[row];
		col = 0;
		while (line[col] && col < map_info.width)
		{
			sp.x = col * game->minimap_info.b_size;
			sp.y = row * game->minimap_info.b_size;
			if (line[col] == '1')
				draw_square(&sp, game->minimap_info.b_size, 0xffffff,
						&game->gl);
			// ft_put_img(&game->gl, game->minimap_info.wall,
			// 		* game->minimap_info.b_size, row
			// 		* game->minimap_info.b_size);
			else
				draw_square(&sp, game->minimap_info.b_size, 0x000000,
						&game->gl);
			// ft_put_img(&game->gl, game->minimap_info.space, col
			// 		* game->minimap_info.b_size, row
			// 		* game->minimap_info.b_size);
			col++;
		}
		while (col < map_info.width)
		{
			sp.x = col * game->minimap_info.b_size;
			sp.y = row * game->minimap_info.b_size;
			draw_square(&sp, game->minimap_info.b_size, 0x000000, &game->gl);
			col++;
		}
		row++;
	}
}

void	draw_minimap(t_game *game, t_ray *ray)
{
	int		b_size;
	t_point	pos;
	t_point	sp;
	t_point	ep;

	b_size = game->minimap_info.b_size;
	pos = game->state.pos;
	sp.x = game->minimap_info.b_size * game->state.pos.x;
	sp.y = game->minimap_info.b_size * game->state.pos.y;
	if (ray->side == X)
	{
		ep.y = b_size * (pos.y + ray->perp_wall_dist * ray->ray_dir.y);
		ep.x = b_size * (pos.x + ray->perp_wall_dist * ray->ray_dir.x);
	}
	else
	{
		ep.y = b_size * (pos.y + ray->perp_wall_dist * ray->ray_dir.y);
		ep.x = b_size * (pos.x + ray->perp_wall_dist * ray->ray_dir.x);
	}
	draw_minimap_bg(game);
	draw_minimap_player(game);
	draw_line(&sp, &ep, &game->gl);
	// printf("bsize: %d\n", b_size);
	// printf("pos : %d, %d\n", pos);
	printf("sp : %lf, %lf\n", sp.x, sp.y);
	printf("ep : %lf, %lf\n", ep.x, ep.y);
}
