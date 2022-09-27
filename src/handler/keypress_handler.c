#include "draw.h"
#include "handler.h"
#include "math.h"
#include "raycast.h"

static void	move_pos(int key, t_point *pos)
{
	if (key == KEY_A)
	{
		pos->x -= STEP;
	}
	else if (key == KEY_D)
	{
		pos->x += STEP;
	}
	else if (key == KEY_W)
	{
		pos->y -= STEP;
	}
	else if (key == KEY_S)
	{
		pos->y += STEP;
	}
}

static void	rotate_pos(int key, t_point *dir, t_point *plane)
{
	t_point	prev_dir;
	t_point	prev_plane;

	prev_dir = *dir;
	prev_plane = *plane;
	if (key == KEY_RD)
	{
		dir->x = (prev_dir.x * cos(THETA)) - (prev_dir.y * sin(THETA));
		dir->y = (prev_dir.x * sin(THETA)) + (prev_dir.y * cos(THETA));
		plane->x = (prev_plane.x * cos(THETA)) - (prev_plane.y * sin(THETA));
		plane->y = (prev_plane.x * sin(THETA)) + (prev_plane.y * cos(THETA));
	}
	else if (key == KEY_LD)
	{
		dir->x = (prev_dir.x * cos(-THETA)) - (prev_dir.y * sin(-THETA));
		dir->y = (prev_dir.x * sin(-THETA)) + (prev_dir.y * cos(-THETA));
		plane->x = (prev_plane.x * cos(-THETA)) - (prev_plane.y * sin(-THETA));
		plane->y = (prev_plane.x * sin(-THETA)) + (prev_plane.y * cos(-THETA));
	}
}
static void	handle_minimap(int key, t_game *game)
{
	draw_minimap_bg(game);
	move_pos(key, &game->state.pos);
	rotate_pos(key, &game->state.dir, &game->state.plane);
	draw_minimap_bg(game);
	// draw_dir_line(&game->state, game->minimap_info.b_size, &game->gl);
	draw_minimap_player(game);
	raycast(game, game->minimap_info.b_size * game->map_info.width);
}

void	handle_direction_key(int key, t_game *game)
{
	mlx_clear_window(game->gl.mlx_ptr, game->gl.win_ptr);
	handle_minimap(key, game);
}

int	keypress_handler(int key, t_game *game)
{
	if ((key == KEY_A || key == KEY_D || key == KEY_S || key == KEY_W
			|| key == KEY_LD || key == KEY_RD))
		handle_direction_key(key, game);
	return (SUCCESS);
}