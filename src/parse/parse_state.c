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
	if (dir == 'N')
	{
		state->dir.x = 0;
		state->dir.y = -1;
	}
	else if (dir == 'S')
	{
		state->dir.x = 0;
		state->dir.y = 1;
	}
	else if (dir == 'W')
	{
		state->dir.x = -1;
		state->dir.y = 0;
	}
	else if (dir == 'E')
	{
		state->dir.x = 1;
		state->dir.y = 0;
	}
}

static void	set_pos(t_state *state, double x, double y)
{
	state->pos.x = x + 0.5;
	state->pos.y = y + 0.5;
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
		while (col < ft_strlen(line))
		{
			if (ft_strchr("NSEW", line[col]))
			{
				set_pos(state, col, row);
				set_dir(state, line[col]);
				set_plane(state);
				return ;
			}
			col++;
		}
		row++;
	}
}