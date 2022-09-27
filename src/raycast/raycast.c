#include "cub3D.h"
#include "draw.h"
#include "raycast.h"
#include <math.h>

void	raycast(t_game *game, int width)
{
	t_point sp;
	t_point ep;
	t_ray ray;
	double camera_x;
	int i;

	i = 0;
	while (30 * i < width)
	{
		camera_x = 2 * (30 * i) / (double)width - 1;
		init_ray(game, &ray, camera_x);
		ray_dda(&ray, game, &sp, &ep);
		draw_line(&sp, &ep, &game->gl);
		i++;
	}
}