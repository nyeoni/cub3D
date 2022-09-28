#include "cub3D.h"
#include "math.h"

static void	draw_texture(t_game *game, t_ray *ray, int x, int line_height)
{
	int	step;
	int	wall_x;
	int	texture_x;

	step = TEXTURE_SIZE / line_height;
	if (ray->side == X)
	{
		wall_x = game->state.pos.y + ray->perp_wall_dist * ray->ray_dir.y;
		wall_x -= floor(wall_x);
		texture_x = (int)(wall_x * (double)TEXTURE_SIZE);
		if (ray->step_x < 0)
			texture_x = TEXTURE_SIZE - texture_x - 1;
	}
	else
	{
		wall_x = game->state.pos.x + ray->perp_wall_dist * ray->ray_dir.x;
		wall_x -= floor(wall_x);
		texture_x = (int)(wall_x * (double)TEXTURE_SIZE);
		if (ray->step_y < 0)
			texture_x = TEXTURE_SIZE - texture_x - 1;
	}
	return ;
}

void	draw_wall(t_game *game, t_ray *ray, int x)
{
	int	start_y;
	int	end_y;
	int	line_height;

	line_height = WIN_HEIGHT / ray->perp_wall_dist;
	start_y = (WIN_HEIGHT / 2) - (line_height / 2);
	if (start_y < 0)
		start_y = 0;
	end_y = (WIN_HEIGHT / 2) + (line_height / 2);
	while (start_y < end_y)
	{
		if (ray->side == X)
		{
			if (ray->step_x > 0) // east
				mlx_pixel_put(game->gl.mlx_ptr, game->gl.win_ptr, x, start_y,
						0xfff5e4);
			else // west
				mlx_pixel_put(game->gl.mlx_ptr, game->gl.win_ptr, x, start_y,
						0xffc4c4);
		}
		else
		{
			if (ray->step_y > 0) // south
				mlx_pixel_put(game->gl.mlx_ptr, game->gl.win_ptr, x, start_y,
						0xee6983);
			else // north
				mlx_pixel_put(game->gl.mlx_ptr, game->gl.win_ptr, x, start_y,
						0x850e35);
		}
		start_y++;
	}
}

void	draw_game_bg(t_game *game)
{
	t_img_info	*img_info;
	int			pixel;
	int			x;
	int			y;

	img_info = &game->graphic_info.img_info;
	y = 0;
	while (y < WIN_HEIGHT / 2)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			pixel = (y * img_info->size_line) / (img_info->bpp / 8) + x;
			*(img_info->buf
					+ pixel) = (unsigned int)game->graphic_info.color[C];
			pixel = ((y + (WIN_HEIGHT / 2)) * img_info->size_line
					/ (img_info->bpp / 8)) + x;
			*(img_info->buf
					+ pixel) = (unsigned int)game->graphic_info.color[F];
			x++;
		}
		y++;
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
	mlx_put_image_to_window(game->gl.mlx_ptr, game->gl.win_ptr,
			game->graphic_info.img, 0, 0);
}