#include "cub3D.h"
#include "draw.h"
#include "math.h"

static unsigned int	ft_get_img_color(t_img_info *img_info, int x, int y)
{
	int	color_byte;
	int	pixel;

	color_byte = img_info->bpp / 8;
	pixel = (y * img_info->size_line) / color_byte + x;
	return (*(img_info->buf + pixel));
}

int	get_texture_scaled_x(t_point *pos, t_ray *ray)
{
	double	wall_x;
	int		texture_x;

	if (ray->side == X)
		wall_x = pos->y + ray->perp_wall_dist * ray->ray_dir.y;
	else
		wall_x = pos->x + ray->perp_wall_dist * ray->ray_dir.x;
	wall_x = wall_x - floor(wall_x);
	texture_x = (int)(wall_x * (double)TEXTURE_SIZE);
	if (ray->side == X && ray->ray_dir.x < 0)
		texture_x = TEXTURE_SIZE - texture_x - 1;
	if (ray->side == Y && ray->ray_dir.y < 0)
		texture_x = TEXTURE_SIZE - texture_x - 1;
	return (texture_x);
}

void	draw_wall(t_game *game, t_ray *ray, int x)
{
	int				line_height;
	double			ratio;
	int				start_y;
	int				end_y;
	double			texture_pos;
	int				texture_x;
	int				texture_y;
	unsigned int	color;

	line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	ratio = (double)TEXTURE_SIZE / line_height;
	start_y = (WIN_HEIGHT / 2) - (line_height / 2);
	if (start_y < 0)
		start_y = 0;
	end_y = (WIN_HEIGHT / 2) + (line_height / 2);
	if (start_y < 0)
		start_y = 0;
	if (end_y >= WIN_HEIGHT)
		end_y = WIN_HEIGHT;
	texture_x = get_texture_scaled_x(&game->state.pos, ray);
	texture_pos = (start_y - WIN_HEIGHT / 2 + line_height / 2) * ratio;
	while (start_y < end_y)
	{
		texture_y = (int)texture_pos & (TEXTURE_SIZE - 1);
		if (ray->side == X && ray->ray_dir.x > 0) // west
			color = ft_get_img_color(&game->graphic_info.texture_info[WE],
										texture_x,
										texture_y);
		else if (ray->side == X && ray->ray_dir.x < 0) // east
			color = ft_get_img_color(&game->graphic_info.texture_info[EA],
										texture_x,
										texture_y);
		else if (ray->side == Y && ray->ray_dir.y > 0) // north
			color = ft_get_img_color(&game->graphic_info.texture_info[NO],
										texture_x,
										texture_y);
		else if (ray->side == Y && ray->ray_dir.y < 0) // south
			color = ft_get_img_color(&game->graphic_info.texture_info[SO],
										texture_x,
										texture_y);
		draw_pixel(&game->graphic_info.img_info, x, start_y, color);
		texture_pos += ratio;
		start_y++;
	}
}

void	draw_game_bg(t_game *game)
{
	t_img_info	*img_info;
	int			x;
	int			y;

	img_info = &game->graphic_info.img_info;
	y = -1;
	while (++y < WIN_HEIGHT / 2)
	{
		x = -1;
		while (++x < WIN_WIDTH)
		{
			draw_pixel(img_info, x, y, game->graphic_info.color[C]);
			draw_pixel(img_info, x, y + (WIN_HEIGHT / 2),
					game->graphic_info.color[F]);
		}
	}
}

void	draw_game(t_game *game)
{
	int		x;
	t_ray	ray;
	double	camera_x;

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
