#include "cub3D.h"
#include "parse.h"
#include "raycast.h"

int	check_wall_collision(t_point next_pos, t_state *state, t_game *game)
{
	t_game	tmp_game;
	t_ray	ray;
	double	camera_x;
	int		x;

	x = 0;
	set_pos(&tmp_game.state, state->pos.x, state->pos.y);
	set_dir(&tmp_game.state, next_pos.x - state->pos.x, next_pos.y
			- state->pos.y);
	set_plane(&tmp_game.state);
	tmp_game.map_info.map = game->map_info.map;
	while (x < WIN_WIDTH)
	{
		camera_x = 2 * x / (double)WIN_WIDTH - 1;
		ray = raycast(&tmp_game, camera_x);
		if (ray.perp_wall_dist < STEP)
		{
			printf("too close to the wall!\n");
			return (FAIL);
		}
		x++;
	}
	return (SUCCESS);
}
