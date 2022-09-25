#include "cub3D.h"
#include "draw.h"
#include <math.h>

void	raycast(t_game *game, int width)
{
	// win_width loop
	// int x = 0;
	// while (x < WIN_WIDTH)
	// {

	// 	x++;
	// }

	int hit = 0;
	double cameraX = 2 * 0 / (double)width - 1;
	// dirX, dirY, planeX, planeY -> game->state.*에 존재

	double rayDirX = game->state.dir.x + cameraX * game->state.plane.x;
	double rayDirY = game->state.dir.y + cameraX * game->state.plane.y;

	int mapX = (int)game->state.pos.x;
	int mapY = (int)game->state.pos.y;

	// sideDistX
	// sideDistY

	double deltaDistX = (rayDirY == 0) ? 0 : ((rayDirX == 0) ? 1 : fabs(1
				/ rayDirX));
	double deltaDistY = (rayDirX == 0) ? 0 : ((rayDirY == 0) ? 1 : fabs(1
				/ rayDirY));

	// ray 사용할 변수 초기화
	// sideDistX, sideDistY, deltaDistX, deltaDistY, stepX, stepY
	// sideDistX, sideDistY 값 비교 -> 작은 값 먼저 hit 확인
}