#include "cub3D.h"
#include "draw.h"
#include "game.h"
#include "math.h"
#include "raycast.h"
#include "util.h"

// void	*make_img(t_game *game, int color_type)
// {
// 	t_img_info	comp_info;
// 	void		*img;
// 	int			pixel;

// 	img = mlx_new_image(game->gl.mlx_ptr, WIN_WIDTH, WIN_HEIGHT / 2);
// 	comp_info.buf = mlx_get_data_addr(img, &comp_info.bpp, &comp_info.size_line,
// 			&comp_info.endian);
// 	for (int y = 0; y < WIN_HEIGHT / 2; y++)
// 	{
// 		for (int x = 0; x < WIN_WIDTH; x++)
// 		{
// 			pixel = (y * comp_info.size_line) + (x * 4);
// 			*(unsigned int *)(comp_info.buf
// 					+ pixel) = (unsigned int)game->graphic_info.bg_color[color_type];
// 		}
// 	}
// 	return (img);
// }

// void	create_bg_img(t_game *game)
// {
// 	game->graphic_info.bg_img[C] = make_img(game, C);
// 	game->graphic_info.bg_img[F] = make_img(game, F);
// }

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