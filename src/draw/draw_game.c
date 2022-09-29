#include "cub3D.h"
#include "draw.h"
#include "mlx.h"
#include "raycast.h"

static void	draw_game_bg(t_graphic_info *graphic_info)
{
	t_img_info	*img_info;
	int			x;
	int			y;

	img_info = &graphic_info->img_info;
	y = -1;
	while (++y < WIN_HEIGHT / 2)
	{
		x = -1;
		while (++x < WIN_WIDTH)
		{
			draw_pixel(img_info, x, y, graphic_info->color[C]);
			draw_pixel(img_info, x, y + (WIN_HEIGHT / 2),
					graphic_info->color[F]);
		}
	}
}

void	draw_game(t_game *game)
{
	int		x;
	t_ray	ray;
	double	camera_x;

	x = 0;
	draw_game_bg(&game->graphic_info);
	while (x < WIN_WIDTH)
	{
		camera_x = 2 * x / (double)WIN_WIDTH - 1;
		ray = raycast(&game->state, game->map_info.map, camera_x);
		draw_wall(game, &ray, x);
		x++;
	}
	mlx_put_image_to_window(game->gl.mlx_ptr, game->gl.win_ptr,
			game->graphic_info.img, 0, 0);
}
