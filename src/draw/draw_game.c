#include "cub3D.h"

void	draw_wall(t_game *game, t_ray *ray, int x)
{
	int	start_point;
	int	end_point;
	int	line_height;

	line_height = WIN_HEIGHT / ray->perp_wall_dist;
	start_point = (WIN_HEIGHT / 2) - (line_height / 2);
	if (start_point < 0)
		start_point = 0;
	end_point = (WIN_HEIGHT / 2) + (line_height / 2);
	while (start_point < end_point)
	{
		mlx_pixel_put(game->gl.mlx_ptr, game->gl.win_ptr, x, start_point,
				0x00ffff);
		start_point++;
	}
}

void	draw_game_bg(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < WIN_HEIGHT / 2)
	{
		col = 0;
		while (col < WIN_WIDTH)
		{
			mlx_pixel_put(game->gl.mlx_ptr, game->gl.win_ptr, col, row,
					game->graphic_info.color[C]);
			col++;
		}
		row++;
	}
	while (row < WIN_HEIGHT)
	{
		col = 0;
		while (col < WIN_WIDTH)
		{
			mlx_pixel_put(game->gl.mlx_ptr, game->gl.win_ptr, col, row,
					game->graphic_info.color[F]);
			col++;
		}
		row++;
	}
}

void	draw_game(t_game *game)
{
	int x;
	t_ray ray;
	double camera_x;

	x = 0;
	draw_game_bg(game);
	while (x < WIN_WIDTH)
	{
		camera_x = 2 * x / (double)WIN_WIDTH - 1;
		ray = raycast(game, camera_x);
		draw_wall(game, &ray, x);
		x++;
	}
}