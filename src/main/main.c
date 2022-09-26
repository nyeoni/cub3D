#include "cub3D.h"
#include "error.h"
#include "init.h"
#include "libft.h"
#include "mlx.h"
#include "parse.h"
#include "test.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
		throw_error("Error: no file argument\n");
	init(&game);
	parse(argv[1], &game);
	// init_game
	// parse_map
	// start game? or run game?
	minimap(&game);
	mlx_hook(game.gl.win_ptr, KeyPress, 0, &keypress_handler, &game);
	// mlx_hook(game.win_ptr, KEY_EXIT, 0, &exit, 0);
	mlx_loop(game.gl.mlx_ptr);
	return (0);
}