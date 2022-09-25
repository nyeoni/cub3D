#include "draw.h"
#include "math.h"
#include "minimap.h"
#include "util.h"

void	minimap(t_game *game)
{
	int height, width;

	width = game->map_info.width;
	height = game->map_info.height;
	game->gl.win_ptr = mlx_new_window(game->gl.mlx_ptr, MINI_IMG_SIZE * width,
			MINI_IMG_SIZE * height, "minimap");

	draw_minimap_bg(game);
	draw_dir_line(&game->state, &game->gl);
	draw_minimap_player(game, MINIMAP_PLAYER);

	for (int x = 0; x < WIN_WIDTH; x++)
	{
		double cameraX = 2 * x / (double)WIN_WIDTH - 1;
		double rayDirX = game->state.dir.x + game->state.plane.x * cameraX;
		double rayDirY = game->state.dir.y + game->state.plane.y * cameraX;

		int mapX = (int)game->state.pos.x;
		int mapY = (int)game->state.pos.y;

		double sideDistX;
		double sideDistY;

		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);
		double perpWallDist;

		int stepX;
		int stepY;

		int hit = 0;
		int side;

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (game->state.pos.x - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - game->state.pos.x) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (game->state.pos.y - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - game->state.pos.y) * deltaDistY;
		}

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
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			//Check if ray has hit a wall
			if (game->map_info.map[mapY][mapX] > 0)
				hit = 1;
		}
		t_point ep;
		if (side == 0)
		{
			ep.x = MINI_IMG_SIZE * mapX;
			ep.y = ep.x * (rayDirY / rayDirX);
		}
		else
		{
			ep.y = MINI_IMG_SIZE * mapY;
			ep.x = ep.y * (rayDirX / rayDirY);
		}
		draw_line(&game->state.pos, &ep, &game->gl);
	}
}