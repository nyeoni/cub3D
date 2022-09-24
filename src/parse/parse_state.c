#include "cub3D.h"
#include "libft.h"

static void	set_plane(t_state *state)
{
	t_point	dir;

	dir = state->dir;
	if (dir.x == 0)
		state->plane.x = 1;
	else if (dir.x != 0)
		state->plane.x = 0;
	if (dir.y == 0)
		state->plane.y = 1;
	else if (dir.y != 0)
		state->plane.y = 0;
}

static void	set_dir(t_state *state, char dir)
{
	if (dir == NO)
	{
		state->dir.x = 0;
		state->dir.y = -1;
	}
	else if (dir == SO)
	{
		state->dir.x = 0;
		state->dir.y = 1;
	}
	else if (dir == WE)
	{
		state->dir.x = -1;
		state->dir.y = 0;
	}
	else if (dir == EA)
	{
		state->dir.x = 1;
		state->dir.y = 0;
	}
}

static void	set_pos(t_state *state, double x, double y)
{
	state->pos.x = x;
	state->pos.y = y;
}

void	parse_state(t_state *state, t_map_info *map_info)
{
	char *line;
	int row;
	int col;

	row = 0;
	while (row < map_info->height)
	{
		line = map_info->map[row];
		col = 0;
		while (col < map_info->width)
		{
			if (ft_strchr("NSEW", line[col]))
			{
				set_pos(state, col, row);
				set_dir(state, line[col]);
				set_plane(state);
				break ;
			}
			col++;
		}
		row++;
	}
}