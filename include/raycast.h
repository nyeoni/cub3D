#ifndef RAYCAST_H
# define RAYCAST_H

# include "cub3D.h"

void	raycast(t_game *game, int width);
void	ray_dda(t_ray *ray, t_game *game, t_point *sp, t_point *ep);

#endif