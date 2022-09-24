#include "draw.h"
#include "minimap.h"
#include "util.h"

void	minimap(t_game *game)
{
	int height, width;

	width = game->map_info.width;
	height = game->map_info.height;
	game->gl.win_ptr = mlx_new_window(game->gl.mlx_ptr, BLOCK_SIZE * width,
			BLOCK_SIZE * height, "minimap");

	draw_minimap_bg(game);
	draw_minimap_player(game, MINIMAP_PLAYER);
}