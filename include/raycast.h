#ifndef RAYCAST_H
# define RAYCAST_H

# include "cub3D.h"

typedef struct s_ray
{
	t_point	ray_dir;
	t_point	side_dist;
	t_point	delta_dist;
	int		map_x;
	int		map_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		side;
	double	ratio;
}			t_ray;

t_ray		raycast(t_game *game, double camera_x);
void	init_ray(t_game *game,
				t_ray *ray,
				double camera_x);

#endif