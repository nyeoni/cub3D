#include "cub3D.h"
#include "draw.h"
#include "game.h"
#include "math.h"
#include "raycast.h"
#include "util.h"

void	start_game(t_game *game)
{
	game->gl.win_ptr = mlx_new_window(game->gl.mlx_ptr,
										WIN_WIDTH,
										WIN_HEIGHT,
										"cub3D");
	draw_game(game);
	draw_minimap(game);
}