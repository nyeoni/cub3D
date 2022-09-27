#include "cub3D.h"
#include "draw.h"
#include "raycast.h"

void	raycast(t_game *game, int width)
{
	t_point sp;
	t_point ep;
	t_ray ray;
	double camera_x;
	int i;

	i = 0;
	// while (30 * i < WIN_WIDTH)
	while (30 * i < width)
	{
		camera_x = 2 * (30 * i) / (double)width - 1;
		// camera_x = 2 * (30 * i) / (double)WIN_WIDTH - 1;
		init_ray(game, &ray, camera_x);
		ray_dda(&ray, game);
		draw_minimap(game, &ray);
		// draw window
		i++;
	}
}