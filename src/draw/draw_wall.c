#include "cub3D.h"
#include "draw.h"
#include "math.h"
#include "raycast.h"

static unsigned int	get_img_color(t_img_info *img_info, int x, int y)
{
	int	color_byte;
	int	pixel;

	color_byte = img_info->bpp / 8;
	pixel = (y * img_info->size_line) / color_byte + x;
	return (*(img_info->buf + pixel));
}

static int	get_texture_scaled_x(t_point *pos, t_ray *ray)
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
	if (ray->side == Y && ray->ray_dir.y > 0)
		texture_x = TEXTURE_SIZE - texture_x - 1;
	return (texture_x);
}

t_render_info	get_render_info(t_ray *ray, t_state *state)
{
	t_render_info	render_info;

	render_info.line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	render_info.ratio = (double)TEXTURE_SIZE / render_info.line_height;
	render_info.start_y = (WIN_HEIGHT / 2) - (render_info.line_height / 2);
	render_info.end_y = (WIN_HEIGHT / 2) + (render_info.line_height / 2);
	if (render_info.start_y < 0)
		render_info.start_y = 0;
	if (render_info.end_y >= WIN_HEIGHT)
		render_info.end_y = WIN_HEIGHT;
	render_info.tex_x = get_texture_scaled_x(&state->pos, ray);
	render_info.tex_pos = (render_info.start_y - WIN_HEIGHT / 2
			+ render_info.line_height / 2) * render_info.ratio;
	return (render_info);
}

void	draw_wall(t_game *game, t_ray *ray, int x)
{
	int color;
	t_render_info info;
	t_img_info *tex_info;
	t_img_info *img_info;

	img_info = &game->graphic_info.img_info;
	info = get_render_info(ray, &game->state);
	tex_info = game->graphic_info.texture_info;
	while (info.start_y < info.end_y)
	{
		info.tex_y = (int)info.tex_pos & (TEXTURE_SIZE - 1);
		if (ray->side == X && ray->ray_dir.x > 0)
			color = get_img_color(&tex_info[WE], info.tex_x, info.tex_y);
		else if (ray->side == X && ray->ray_dir.x < 0)
			color = get_img_color(&tex_info[EA], info.tex_x, info.tex_y);
		else if (ray->side == Y && ray->ray_dir.y > 0)
			color = get_img_color(&tex_info[NO], info.tex_x, info.tex_y);
		else if (ray->side == Y && ray->ray_dir.y < 0)
			color = get_img_color(&tex_info[SO], info.tex_x, info.tex_y);
		draw_pixel(img_info, x, info.start_y, color);
		info.tex_pos += info.ratio;
		info.start_y++;
	}
}