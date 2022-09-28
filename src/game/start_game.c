#include "cub3D.h"
#include "draw.h"
#include "game.h"
#include "math.h"
#include "raycast.h"
#include "util.h"

void	start_game(t_game *game)
{
	t_img_info img_info;

	game->gl.win_ptr = mlx_new_window(game->gl.mlx_ptr,
										WIN_WIDTH,
										WIN_HEIGHT,
										"minimap");
	if (game->map_info.width < game->map_info.height)
		game->minimap_info.b_size = MINI_WIN_SIZE / game->map_info.height;
	else
		game->minimap_info.b_size = MINI_WIN_SIZE / game->map_info.width;
	game->graphic_info.img = mlx_new_image(game->gl.mlx_ptr, WIN_WIDTH,
			WIN_HEIGHT);
	img_info.buf = (unsigned int *)mlx_get_data_addr(game->graphic_info.img,
														&img_info.bpp,
														&img_info.size_line,
														&img_info.endian);
	game->graphic_info.img_info = img_info;
	// create_bg_img(game);
	draw_game(game);
	draw_minimap(game);
}