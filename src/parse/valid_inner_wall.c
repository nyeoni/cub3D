#include "cub3D.h"
#include "error.h"
#include "libft.h"
#include "parse.h"

static void	check_space(char **map, int row, int col, int arrow)
{
	if (arrow == UP)
		arrow = map[row - 1][col];
	else if (arrow == DOWN)
		arrow = map[row + 1][col];
	else if (arrow == LEFT)
		arrow = map[row][col - 1];
	else if (arrow == RIGHT)
		arrow = map[row][col + 1];
	if (arrow != SPACE && arrow != WALL)
		throw_error("InvalidMapError : space must be surrounded by wall!");
}

static void	check_side_space(char **map, int row, int col)
{
	int	len;

	len = ft_strlen(map[row]);
	if (col == 0)
	{
		check_space(map, row, col, RIGHT);
	}
	else if (col == len - 1)
	{
		check_space(map, row, col, LEFT);
	}
	else
	{
		check_space(map, row, col, LEFT);
		check_space(map, row, col, RIGHT);
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
		if (line[col] == SPACE)
		{
			if (row == 0)
			{
				check_space(map_info->map, row, col, DOWN);
			}
			else if (row == map_info->height - 1)
			{
				check_space(map_info->map, row, col, UP);
			}
			else
			{
				check_space(map_info->map, row, col, UP);
				check_space(map_info->map, row, col, DOWN);
			}
			check_side_space(map_info->map, row, col);
		}
		col++;
	}
}
