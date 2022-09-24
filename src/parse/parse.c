#include "parse.h"

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
}
