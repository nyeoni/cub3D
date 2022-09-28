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
		if (ray->side == X)
		{
			if (ray->step_x > 0) // east
				mlx_pixel_put(game->gl.mlx_ptr, game->gl.win_ptr, x,
						start_point, 0xfff5e4);
			else // west
				mlx_pixel_put(game->gl.mlx_ptr, game->gl.win_ptr, x,
						start_point, 0xffc4c4);
		}
		else
		{
			if (ray->step_y > 0) // south
				mlx_pixel_put(game->gl.mlx_ptr, game->gl.win_ptr, x,
						start_point, 0xee6983);
			else // north
				mlx_pixel_put(game->gl.mlx_ptr, game->gl.win_ptr, x,
						start_point, 0x850e35);
		}
		start_point++;
	}
}

void	draw_game_bg(t_game *game)
{
	int	row;
	int	col;

	mlx_put_image_to_window(game->gl.mlx_ptr, game->gl.win_ptr,
			game->graphic_info.bg_img[C], 0, 0);
	mlx_put_image_to_window(game->gl.mlx_ptr, game->gl.win_ptr,
			game->graphic_info.bg_img[F], 0, WIN_HEIGHT / 2);
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