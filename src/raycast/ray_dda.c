#include "cub3D.h"
#include <stdio.h>

void	ray_dda(t_ray *ray, t_game *game, t_point *sp, t_point *ep)
{
	int hit;

	hit = 0;
	while (hit == 0)
	{
		//jump to next map square, OR in x-direction, OR in y-direction
		if (ray->sideDistX < ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			ray->mapX += ray->stepX;
			ray->side = 0;
		}
		else if (ray->sideDistX == ray->sideDistY)
		{
			ray->sideDistX += ray->deltaDistX;
			ray->sideDistY += ray->deltaDistY;
			ray->mapX += ray->stepX;
			ray->mapY += ray->stepY;
			ray->side = 0;
		}
		else
		{
			ray->sideDistY += ray->deltaDistY;
			ray->mapY += ray->stepY;
			ray->side = 1;
		}
		printf("--map: (%d, %d)\n", ray->mapX, ray->mapY);
		if (game->map_info.map[ray->mapY][ray->mapX] == WALL)
		{
			hit = 1;
			// printf("hit: (%d, %d)\n", mapX, mapY);
		}
	}
	if (ray->side == 0)
		ray->perpWallDist = (ray->mapX - game->state.pos.x + (1 - ray->stepX)
				/ 2) / ray->rayDirX;
	else
		ray->perpWallDist = (ray->mapY - game->state.pos.y + (1 - ray->stepY)
				/ 2) / ray->rayDirY;
	// printf("per: %lf\n", perpWallDist);
	sp->x = game->minimap_info.b_size * game->state.pos.x;
	sp->y = game->minimap_info.b_size * game->state.pos.y;
	if (ray->side == 0)
	{
		ep->y = game->minimap_info.b_size * (game->state.pos.y
				+ ray->perpWallDist * ray->rayDirY);
		ep->x = game->minimap_info.b_size * (game->state.pos.x
				+ ray->perpWallDist * ray->rayDirX);
	}
	else
	{
		ep->y = game->minimap_info.b_size * (game->state.pos.y
				+ ray->perpWallDist * ray->rayDirY);
		ep->x = game->minimap_info.b_size * (game->state.pos.x
				+ ray->perpWallDist * ray->rayDirX);
	}
	// printf("sp: (%lf, %lf)\n", sp->x, sp->y);
	// printf("ep: (%lf, %lf)\n", ep->x, ep->y);
}