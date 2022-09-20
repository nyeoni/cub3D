#include "cub3D.h"
#include "error.h"
#include "libft.h"


// left		: map[row][col - 1]
// right	: map[row][col + 1]
// up		: map[row - 1][col]
// down		: map[row + 1][col]
static void	check_left(const char **map, int row, int col)
{
	char left;

	left = map[row][col - 1];
	if (left != ' ' && left != '1')
		throw_error("InvalidMapError : space must be surrounded by wall!");
}

static void	check_rigth(const char **map, int row, int col)
{
	char right;

	right = map[row][col + 1];
	if (right != ' ' && right != '1')
		throw_error("InvalidMapError : space must be surrounded by wall!");
}

static void	check_up(const char **map, int row, int col)
{
	char up;

	up = map[row - 1][col];
	if (up != ' ' && up != '1')
		throw_error("InvalidMapError : space must be surrounded by wall!");
}

static void	check_down(const char **map, int row, int col)
{
	char down;

	down = map[row + 1][col];
	if (down != ' ' && down != '1')
		throw_error("InvalidMapError : space must be surrounded by wall!");
}

static void	check_space(const char **map, int row, int col)
{
	char	*line;
	int		len;

	line = map[row];
	len = ft_strlen(line);
	check_up(map, row, col);
	check_down(map, row, col);
	if (col == 0)				// right, up, down
	{
		check_rigth(map, row, col);
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

static void	check_space_last(const char **map, int row, int col)
{
	char	*line;
	int		len;

	line = map[row];
	len = ft_strlen(line);
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

static void	check_space_first(const char **map, int row, int col)
{
	char	*line;
	int		len;

	line = map[row];
	len = ft_strlen(line);
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

void	valid_inner_wall(const t_map_info *map_info, int row)
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