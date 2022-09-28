#include "init.h"

void	init(t_game *game)
{
	game->gl.mlx_ptr = mlx_init();
	init_map_info(&game->map_info);
	init_graphic_info(&game->graphic_info, &game->gl);
	init_state(&game->state);
}