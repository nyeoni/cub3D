#include "cub3D.h"
#include "draw.h"
#include "raycast.h"

void	draw_ray(t_game *game, t_ray *ray)
{
	int b_size;
	t_point pos;
	t_point sp;
	t_point ep;

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
	draw_line(&sp, &ep, &game->gl);
}