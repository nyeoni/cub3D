#include "cub3D.h"
#include "error.h"
#include "parse.h"
#include <fcntl.h>

void	parse(char *filename, t_game *game)
{
	int	fd;

	valid_extension(filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		throw_error("FileError : error when open file");
	parse_graphic_info(&game->graphic_info, fd, game->gl.mlx_ptr);
	parse_map_info(&game->map_info, fd);
	valid_map(game);
	parse_state(&game->state, &game->map_info);
	if (game->map_info.width < game->map_info.height)
		game->minimap_info.b_size = MINI_WIN_SIZE / game->map_info.height;
	else
		game->minimap_info.b_size = MINI_WIN_SIZE / game->map_info.width;
}
