/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_wall_collision.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:48:44 by nkim              #+#    #+#             */
/*   Updated: 2022/09/29 17:48:44 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "parse.h"
#include "raycast.h"

int	check_wall_collision(t_point next_pos, t_state *state, char **map)
{
	t_state	move_state;
	t_ray	ray;
	double	camera_x;
	int		x;

	x = 0;
	set_pos(&move_state, state->pos.x, state->pos.y);
	set_dir(&move_state, next_pos.x - state->pos.x, next_pos.y - state->pos.y);
	set_plane(&move_state);
	while (x < WIN_WIDTH)
	{
		camera_x = 2 * x / (double)WIN_WIDTH - 1;
		ray = raycast(&move_state, map, camera_x);
		if (ray.perp_wall_dist < STEP)
			return (FAIL);
		x++;
	}
	return (SUCCESS);
}
