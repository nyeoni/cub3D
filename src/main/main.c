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

void	init_minimap_info(t_minimap_info *minimap_info, t_gl *gl)
{
	minimap_info->wall = ft_make_img(gl->mlx_ptr, "wall.xpm");
	minimap_info->space = ft_make_img(gl->mlx_ptr, "space.xpm");
	minimap_info->pos.x = 0;
	minimap_info->pos.y = 0;
}

void	init(t_game *game)
{
	game->gl.mlx_ptr = mlx_init();
	init_map_info(&game->map_info);
	init_graphic_info(&game->graphic_info);
	init_minimap_info(&game->minimap_info, &game->gl);
	game->pos.x = 0;
	game->pos.y = 0;
}

void	tmp_player_pos_init(t_game *game)
{
	char	*line;

	int col, row;
	row = 0;
	line = game->map_info.map[row];
	while (line)
	{
		col = 0;
		while (line[col])
		{
			if (ft_strchr("NSEW", line[col]))
			{
				game->pos.x = col;
				game->pos.y = row;
				game->dir.x = 0;
				game->dir.y = 0;
				if (line[col] == 'N')
					game->dir.y = 1;
				else if (line[col] == 'S')
					game->dir.y = -1;
				else if (line[col] == 'E')
					game->dir.x = 1;
				else
					game->dir.x = -1;
				game->minimap_info.pos.x = col * BLOCK_SIZE;
				game->minimap_info.pos.y = row * BLOCK_SIZE;
				return ;
			}
			col++;
		}
		line = game->map_info.map[++row];
	}
}

int	main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
		throw_error("Error: no file argument\n");
	init(&game);
	parse(argv[1], &game);
	print_info(&game);
	tmp_player_pos_init(&game);

	minimap(&game);
	mlx_hook(game.gl.win_ptr, KeyPress, 0, &keypress_handler, &game);
	// mlx_hook(game.win_ptr, KEY_EXIT, 0, &exit, 0);
	mlx_loop(game.gl.mlx_ptr);
	return (0);
}