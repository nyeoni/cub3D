#ifndef RAYCAST_H
# define RAYCAST_H

# include "cub3D.h"

void	raycast(t_game *game, int width);
void	init_ray(t_game *game, t_ray *ray, double camera_x);
void	ray_dda(t_ray *ray, t_game *game);

#endif