#include "draw.h"
#include "math.h"
#include "minimap.h"
#include "raycast.h"
#include "util.h"

void	minimap(t_game *game)
{
	game->minimap_info.b_size = MINI_WIN_HEIGHT / game->map_info.height;
	game->gl.win_ptr = mlx_new_window(game->gl.mlx_ptr,
										game->minimap_info.b_size
											* game->map_info.width,
										MINI_WIN_HEIGHT,
										"minimap");

	draw_minimap_bg(game);
	draw_dir_line(&game->state, game->minimap_info.b_size, &game->gl);
	draw_minimap_player(game);

	raycast(game, game->minimap_info.b_size * game->map_info.width);
}