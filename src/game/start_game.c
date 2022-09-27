#include "draw.h"
#include "game.h"
#include "math.h"
#include "raycast.h"
#include "util.h"

void	minimap(t_game *game)
{
	int	max_cnt;

	if (game->map_info.width < game->map_info.height)
		game->minimap_info.b_size = MINI_WIN_SIZE / game->map_info.height;
	else
		game->minimap_info.b_size = MINI_WIN_SIZE / game->map_info.width;
	draw_minimap_bg(game);
	// draw_dir_line(&game->state, game->minimap_info.b_size, &game->gl);
	draw_minimap_player(game);
	raycast(game, game->minimap_info.b_size * game->map_info.width);
}

void	start_game(t_game *game)
{
	game->gl.win_ptr = mlx_new_window(game->gl.mlx_ptr,
										WIN_WIDTH,
										WIN_HEIGHT,
										"minimap");
	minimap(game);
}