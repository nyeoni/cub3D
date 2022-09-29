#include "cub3D.h"
#include "raycast.h"

int	check_wall_collision(t_point next_pos, t_state *state, t_game *game)
{
	int		x;
	t_ray	ray;
	t_game	tmp_game;
	t_point	dir;
	double	camera_x;

	if (next_pos.x - state->pos.x > 0)
		dir.x = 1;
	else if (next_pos.x - state->pos.x < 0)
		dir.x = -1;
	else
		dir.x = 0;
	if (next_pos.y - state->pos.y > 0)
		dir.y = 1;
	else if (next_pos.y - state->pos.y < 0)
		dir.y = -1;
	else
		dir.y = 0;
	// raycast
	x = 0;
	tmp_game.state.dir.x = dir.x;
	tmp_game.state.dir.y = dir.y;
	tmp_game.state.plane.x = game->state.plane.x;
	tmp_game.state.plane.y = game->state.plane.y;
	tmp_game.state.pos.x = state->pos.x;
	tmp_game.state.pos.y = state->pos.y;
	tmp_game.map_info.map = game->map_info.map;
	while (x < WIN_WIDTH)
	{
		camera_x = 2 * x / (double)WIN_WIDTH - 1;
		ray = raycast(&tmp_game, camera_x);
		if (ray.perp_wall_dist < 0.1)
		{
			printf("too close wall!!!!!!!\n");
			return (FAIL);
		}
		x++;
	}
	return (SUCCESS);
}
