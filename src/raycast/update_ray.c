#include "raycast.h"

void	update_ray(t_ray *ray, int axis)
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