#include "cub3D.h"
#include "draw.h"
#include <math.h>

void	raycast(t_game *game, int width)
{
	double cameraX;
	double rayDirX;
	double rayDirY;
	int mapX;
	int mapY;
	double sideDistX;
	double sideDistY;
	double deltaDistX;
	double deltaDistY;
	double perpWallDist;
	int stepX;
	int stepY;
	int hit;
	int side;
	t_point sp;
	t_point ep;

	for (int i = 0; 30 * i < width; i++)
	{
		cameraX = 2 * (30 * i) / (double)width - 1;
		rayDirX = game->state.dir.x + game->state.plane.x * cameraX;
		rayDirY = game->state.dir.y + game->state.plane.y * cameraX;
		printf("pos: (%lf, %lf)\n", game->state.pos.x, game->state.pos.y);
		mapX = (int)game->state.pos.x;
		mapY = (int)game->state.pos.y;
		printf("map1: (%d, %d)\n", mapX, mapY);
		deltaDistX = (rayDirY == 0) ? 0 : ((rayDirX == 0) ? 1 : fabs(1
					/ rayDirX));
		deltaDistY = (rayDirX == 0) ? 0 : ((rayDirY == 0) ? 1 : fabs(1
					/ rayDirY));
		hit = 0;
		printf("rayDir: (%lf, %lf)\n", rayDirX, rayDirY);
		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (game->state.pos.x - (double)mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - game->state.pos.x) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (game->state.pos.y - (double)mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - game->state.pos.y) * deltaDistY;
		}
		printf("sideDist: (%lf, %lf)\n", sideDistX, sideDistY);
		printf("step (x, y): (%d, %d)\n", stepX, stepY);
		//perform DDA
		while (hit == 0)
		{
			//jump to next map square, OR in x-direction, OR in y-direction
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else if (sideDistX == sideDistY)
			{
				sideDistX += deltaDistX;
				sideDistY += deltaDistY;
				mapX += stepX;
				mapY += stepY;
				side = 0;
			}
			else
			{
				printf("fuck");
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			printf("--map: (%d, %d)\n", mapX, mapY);
			if (game->map_info.map[mapY][mapX] == WALL)
			{
				hit = 1;
				printf("hit: (%d, %d)\n", mapX, mapY);
			}
		}
		if (side == 0)
			perpWallDist = (mapX - game->state.pos.x + (1 - stepX) / 2)
				/ rayDirX;
		else
			perpWallDist = (mapY - game->state.pos.y + (1 - stepY) / 2)
				/ rayDirY;
		printf("per: %lf\n", perpWallDist);
		sp.x = game->minimap_info.b_size * game->state.pos.x;
		sp.y = game->minimap_info.b_size * game->state.pos.y;
		double ratio;
		if (side == 0)
		{
			ep.y = game->minimap_info.b_size * (game->state.pos.y + perpWallDist
					* rayDirY);
			ep.x = game->minimap_info.b_size * (game->state.pos.x + perpWallDist
					* rayDirX);
		}
		else
		{
			ep.y = game->minimap_info.b_size * (game->state.pos.y + perpWallDist
					* rayDirY);
			ep.x = game->minimap_info.b_size * (game->state.pos.x + perpWallDist
					* rayDirX);
		}
		printf("sp: (%lf, %lf)\n", sp.x, sp.y);
		printf("ep: (%lf, %lf)\n", ep.x, ep.y);
		draw_line(&sp, &ep, &game->gl);
	}
}