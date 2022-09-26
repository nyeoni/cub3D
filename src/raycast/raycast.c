#include "cub3D.h"
#include "draw.h"
#include "raycast.h"
#include <math.h>

void	init_ray(t_game *game, t_ray *ray, double cameraX)
{
	ray->rayDirX = game->state.dir.x + game->state.plane.x * cameraX;
	ray->rayDirY = game->state.dir.y + game->state.plane.y * cameraX;
	ray->mapX = (int)game->state.pos.x;
	ray->mapY = (int)game->state.pos.y;
	// printf("map1: (%d, %d)\n", ray->mapX, ray->mapY);
	ray->deltaDistX = (ray->rayDirY == 0) ? 0 : ((ray->rayDirX == 0) ? 1 : fabs(1
				/ ray->rayDirX));
	ray->deltaDistY = (ray->rayDirX == 0) ? 0 : ((ray->rayDirY == 0) ? 1 : fabs(1
				/ ray->rayDirY));
	// hit = 0;
	// printf("rayDir: (%lf, %lf)\n", rayDirX, rayDirY);
	if (ray->rayDirX < 0)
	{
		ray->stepX = -1;
		ray->sideDistX = (game->state.pos.x - (double)ray->mapX)
			* ray->deltaDistX;
	}
	else
	{
		ray->stepX = 1;
		ray->sideDistX = (ray->mapX + 1.0 - game->state.pos.x)
			* ray->deltaDistX;
	}
	if (ray->rayDirY < 0)
	{
		ray->stepY = -1;
		ray->sideDistY = (game->state.pos.y - (double)ray->mapY)
			* ray->deltaDistY;
	}
	else
	{
		ray->stepY = 1;
		ray->sideDistY = (ray->mapY + 1.0 - game->state.pos.y)
			* ray->deltaDistY;
	}
	// printf("sideDist: (%lf, %lf)\n", sideDistX, sideDistY);
	// printf("step (x, y): (%d, %d)\n", stepX, stepY);
}

void	raycast(t_game *game, int width)
{
	t_point sp;
	t_point ep;
	t_ray ray;
	double cameraX;

	// ?
	for (int i = 0; 30 * i < width; i++)
	{
		cameraX = 2 * (30 * i) / (double)width - 1;
		init_ray(game, &ray, cameraX);
		ray_dda(&ray, game, &sp, &ep);
		draw_line(&sp, &ep, &game->gl);
	}
}