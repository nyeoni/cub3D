#include "cub3D.h"
#include "draw.h"
#include "raycast.h"
#include <stdio.h>

static void	set_perp_wall_dist(t_ray *ray, t_point *pos)
{
	if (ray->side == X)
		ray->perp_wall_dist = (ray->map_x - pos->x + (1 - ray->step_x) / 2)
			/ ray->ray_dir.x;
	else
		ray->perp_wall_dist = (ray->map_y - pos->y + (1 - ray->step_y) / 2)
			/ ray->ray_dir.y;
}

static void	update_ray(t_ray *ray, int axis)
{
	if (axis == X)
	{
		ray->side_dist.x += ray->delta_dist.x;
		ray->map_x += ray->step_x;
		ray->side = X;
	}
	else
	{
		ray->side_dist.y += ray->delta_dist.y;
		ray->map_y += ray->step_y;
		ray->side = Y;
	}
}

t_ray	raycast(t_game *game, int camera_x)
{
	t_ray	ray;
	int		hit;

	hit = 0;
	init_ray(game, &ray, camera_x);
	while (hit == 0)
	{
		if (ray.side_dist.x < ray.side_dist.y)
			update_ray(&ray, X);
		else if (ray.side_dist.x > ray.side_dist.y)
			update_ray(&ray, Y);
		else
		{
			update_ray(&ray, X);
			update_ray(&ray, Y);
		}
		if (game->map_info.map[ray.map_y][ray.map_x] == WALL)
			hit = 1;
	}
	set_perp_wall_dist(&ray, &game->state.pos);
	return (ray);
}
