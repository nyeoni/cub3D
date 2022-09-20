#include "cub3D.h"
#include "error.h"
#include "libft.h"
#include "mlx.h"
#include "parse.h"
#include "test.h"
#include <fcntl.h>

#define SUCCESS 0
#define FAIL -1

void	init_map_info(t_map_info *map_info)
{
	map_info->map = (char **)ft_calloc(1, sizeof(char *));
	map_info->width = 0;
	map_info->height = 0;
}

void	init_graphic_info(t_graphic_info *graphic_info)
{
	int	i;

	i = 0 - 1;
	while (++i < DIR_TEXTURE_CNT)
		graphic_info->texture[i] = NULL;
	i = 0 - 1;
	while (++i < COLOR_CNT)
		graphic_info->color[i] = -1;
}

void	init(t_game *game)
{
	game->mlx_ptr = mlx_init();
	game->win_ptr = mlx_new_window(game->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
			"cub3D");
	init_map_info(&game->map_info);
	init_graphic_info(&game->graphic_info);
}

int	main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
		throw_error("Error: no file argument\n");
	init(&game);
	parse(argv[1], &game);
	print_info(&game);
}