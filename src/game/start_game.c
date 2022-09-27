#include "cub3D.h"
#include "draw.h"
#include "game.h"
#include "math.h"
#include "raycast.h"
#include "util.h"

void	create_bg_img(t_game *game)
{
	char	*imgbuf;
	void	*img;
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	int		pixel;

	img = mlx_new_image(game->gl.mlx_ptr, WIN_WIDTH, WIN_HEIGHT / 2);
	imgbuf = mlx_get_data_addr(img, &pixel_bits, &line_bytes, &endian);
	for (int y = 0; y < WIN_HEIGHT / 2; y++)
	{
		for (int x = 0; x < WIN_WIDTH; x++)
		{
			pixel = (y * line_bytes) + (x * 4);
			*(unsigned int *)(imgbuf
					+ pixel) = (unsigned int)game->graphic_info.color[C];
		}
	}
	game->graphic_info.bg[C] = img;
	img = mlx_new_image(game->gl.mlx_ptr, WIN_WIDTH, WIN_HEIGHT / 2);
	imgbuf = mlx_get_data_addr(img, &pixel_bits, &line_bytes, &endian);
	for (int y = 0; y < WIN_HEIGHT / 2; y++)
	{
		for (int x = 0; x < WIN_WIDTH; x++)
		{
			pixel = (y * line_bytes) + (x * 4);
			*(unsigned int *)(imgbuf
					+ pixel) = (unsigned int)game->graphic_info.color[F];
		}
	}
	game->graphic_info.bg[F] = img;
}

void	start_game(t_game *game)
{
	game->gl.win_ptr = mlx_new_window(game->gl.mlx_ptr,
										WIN_WIDTH,
										WIN_HEIGHT,
										"minimap");
	if (game->map_info.width < game->map_info.height)
		game->minimap_info.b_size = MINI_WIN_SIZE / game->map_info.height;
	else
		game->minimap_info.b_size = MINI_WIN_SIZE / game->map_info.width;
	create_bg_img(game);
	draw_game(game);
	draw_minimap(game);
}