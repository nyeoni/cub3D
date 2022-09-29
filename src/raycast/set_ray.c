/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ray.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:49:30 by nkim              #+#    #+#             */
/*   Updated: 2022/09/29 17:49:31 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast.h"
#include <math.h>

static void	set_side_dist(t_ray *ray, t_point pos)
{
	if (ray->ray_dir.x < 0)
		ray->side_dist.x = (pos.x - (double)ray->map_x) * ray->delta_dist.x;
	else
		ray->side_dist.x = (ray->map_x + 1.0 - pos.x) * ray->delta_dist.x;
	if (ray->ray_dir.y < 0)
		ray->side_dist.y = (pos.y - (double)ray->map_y) * ray->delta_dist.y;
	else
		ray->side_dist.y = (ray->map_y + 1.0 - pos.y) * ray->delta_dist.y;
}

static void	set_step(t_ray *ray)
{
	if (ray->ray_dir.x < 0)
		ray->step_x = -1;
	else
		ray->step_x = 1;
	if (ray->ray_dir.y < 0)
		ray->step_y = -1;
	else
		ray->step_y = 1;
}

static void	set_delta_dist(t_ray *ray)
{
	if (ray->ray_dir.y == 0)
	{
		ray->delta_dist.x = 0;
	}
	else
	{
		if (ray->ray_dir.x == 0)
			ray->delta_dist.x = 1;
		else
			ray->delta_dist.x = fabs(1 / ray->ray_dir.x);
	}
	if (ray->ray_dir.x == 0)
	{
		ray->delta_dist.y = 0;
	}
	else
	{
		if (ray->ray_dir.y == 0)
			ray->delta_dist.y = 1;
		else
			ray->delta_dist.y = fabs(1 / ray->ray_dir.y);
	}
}

void	set_perp_wall_dist(t_ray *ray, t_point *pos)
{
	if (ray->side == X)
		ray->perp_wall_dist = (ray->map_x - pos->x + (1 - ray->step_x) / 2.0)
			/ ray->ray_dir.x;
	else
		ray->perp_wall_dist = (ray->map_y - pos->y + (1 - ray->step_y) / 2.0)
			/ ray->ray_dir.y;
}

void	set_ray(t_state *state, t_ray *ray, double camera_x)
{
	ray->ray_dir.x = state->dir.x + state->plane.x * camera_x;
	ray->ray_dir.y = state->dir.y + state->plane.y * camera_x;
	ray->map_x = (int)state->pos.x;
	ray->map_y = (int)state->pos.y;
	set_delta_dist(ray);
	set_step(ray);
	set_side_dist(ray, state->pos);
}
