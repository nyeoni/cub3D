#include "cub3D.h"
#include "mlx.h"
#include <stdlib.h>

int	close_game(t_game *game)
{
	mlx_destroy_window(game->gl.mlx_ptr, game->gl.win_ptr);
	exit(SUCCESS);
}