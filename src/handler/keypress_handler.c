#include "draw.h"
#include "handler.h"
#include "math.h"
#include "raycast.h"
#include <stdlib.h>

static void	move_pos(int key, t_state *state)
{
	if (key == KEY_W)
	{
		state->pos.x += STEP * state->dir.x;
		state->pos.y += STEP * state->dir.y;
	}
	else if (key == KEY_D)
	{
		state->pos.x += STEP * state->plane.x;
		state->pos.y += STEP * state->plane.y;
	}
	else if (key == KEY_A)
	{
		state->pos.x += -STEP * state->plane.x;
		state->pos.y += -STEP * state->plane.y;
	}
	else if (key == KEY_S)
	{
		state->pos.x += -STEP * state->dir.x;
		state->pos.y += -STEP * state->dir.y;
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
	// draw_minimap_bg(game);
	move_pos(key, &game->state);
	rotate_pos(key, &game->state.dir, &game->state.plane);
	draw_game(game);
	draw_minimap(game);
}

void	handle_direction_key(int key, t_game *game)
{
	mlx_clear_window(game->gl.mlx_ptr, game->gl.win_ptr);
	handle_minimap(key, game);
}

int	close_game(t_game *game)
{
	mlx_destroy_window(game->gl.mlx_ptr, game->gl.win_ptr);
	exit(SUCCESS);
}

int	keypress_handler(int key, t_game *game)
{
	if ((key == KEY_A || key == KEY_D || key == KEY_S || key == KEY_W
			|| key == KEY_LD || key == KEY_RD))
		handle_direction_key(key, game);
	if (key == KEY_ESC)
		close_game(game);
	return (SUCCESS);
}
