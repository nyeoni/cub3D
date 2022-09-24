#include "draw.h"
#include "handler.h"

static void	move_pos(int key, t_point *pos, int step)
{
	if (key == KEY_A)
	{
		pos->x -= step;
	}
	else if (key == KEY_D)
	{
		pos->x += step;
	}
	else if (key == KEY_W)
	{
		pos->y -= step;
	}
	else if (key == KEY_S)
	{
		pos->y += step;
	}
}

static void	handle_minimap(int key, t_game *game)
{
	draw_minimap_bg(game);
	move_pos(key, &game->minimap_info.pos, MINI_STEP);
	draw_minimap_player(game, MINIMAP_PLAYER);
}

void	handle_direction_key(int key, t_game *game)
{
	mlx_clear_window(game->gl.mlx_ptr, game->gl.win_ptr);
	handle_minimap(key, game);
	// move_pos(key, game);
	// drawPlayer(game, 8);
}

int	keypress_handler(int key, t_game *game)
{
	if ((key == KEY_A || key == KEY_D || key == KEY_S || key == KEY_W))
		handle_direction_key(key, game);
	return (SUCCESS);
}