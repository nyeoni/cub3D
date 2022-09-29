#include "cub3D.h"
#include "draw.h"
#include "game.h"
#include "handler.h"
#include "math.h"

static void	move_pos(int key, t_state *state, t_game *game)
{
	t_point	next_pos;

	if (key == KEY_W)
	{
		next_pos.x = state->pos.x + STEP * state->dir.x;
		next_pos.y = state->pos.y + STEP * state->dir.y;
	}
	else if (key == KEY_D)
	{
		next_pos.x = state->pos.x + STEP * state->plane.x;
		next_pos.y = state->pos.y + STEP * state->plane.y;
	}
	else if (key == KEY_A)
	{
		next_pos.x = state->pos.x + -STEP * state->plane.x;
		next_pos.y = state->pos.y + -STEP * state->plane.y;
	}
	else if (key == KEY_S)
	{
		next_pos.x = state->pos.x + -STEP * state->dir.x;
		next_pos.y = state->pos.y + -STEP * state->dir.y;
	}
	else
		return ;
	if (check_wall_collision(next_pos, state, game) == SUCCESS)
	{
		state->pos.x = next_pos.x;
		state->pos.y = next_pos.y;
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
	// move_pos(key, &game->state);
	move_pos(key, &game->state, game);
	rotate_pos(key, &game->state.dir, &game->state.plane);
	draw_game(game);
	draw_minimap(game);
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
	if (key == KEY_ESC)
		close_game(game);
	return (SUCCESS);
}
