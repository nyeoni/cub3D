#include "cub3D.h"
#include "error.h"
#include "libft.h"
#include "parse.h"

static void	check_space(char **map, int row, int col)
{
	int		len;

	len = ft_strlen(map[row]);
	check_up(map, row, col);
	check_down(map, row, col);
	if (col == 0)				// right, up, down
	{
		check_right(map, row, col);
	}
	else if (col == len - 1)	// left, up, down
	{
		check_left(map, row, col);
	}
	else						// left, right, up, down
	{
		check_right(map, row, col);
		check_left(map, row, col);
	}
}

static void	check_space_last(char **map, int row, int col)
{
	int		len;

	len = ft_strlen(map[row]);
	check_up(map, row, col);
	if (col == 0)				// right, up
	{
		check_right(map, row, col);
	}
	else if (col == len - 1)	// left, up
	{
		check_left(map, row, col);
	}
	else						// left, right, up
	{
		check_left(map, row, col);
		check_right(map, row, col);
	}
}

static void	check_space_first(char **map, int row, int col)
{
	int		len;

	len = ft_strlen(map[row]);
	check_down(map, row, col);
	if (col == 0)				// right, down
	{
		check_right(map, row, col);
	}
	else if (col == len - 1)	// left, down
	{
		check_left(map, row, col);
	}
	else						// left, right, down
	{
		check_left(map, row, col);
		check_right(map, row, col);
	}
}

void	valid_inner_wall(t_map_info *map_info, int row)
{
	char	*line;
	int		col;

	line = map_info->map[row];
	col = 0;
	while (line[col])
	{
		if (line[col] == ' ')
		{
			if (row == 0)
				check_space_first(map_info->map, row, col);
			else if (row == map_info->height - 1)
				check_space_last(map_info->map, row, col);
			else
				check_space(map_info->map, row, col); 
		}
		col++;
	}
}