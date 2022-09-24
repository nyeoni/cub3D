#include "cub3D.h"
#include "error.h"
#include "libft.h"
#include "parse.h"

static void	valid_character(t_map_info *map_info, int row)
{
	char	*line;
	int		col;

	line = map_info->map[row];
	col = 0;
	while (line[col])
	{
		if (ft_strchr("NSEW", line[col]))
		{
			if (map_info->player_x != -1)
				throw_error("InvalidMapError : too many player exist");
			printf("hhere!!!!!\n");
			map_info->player_x = col;
			map_info->player_y = row;
		}
		else if (ft_strchr("01 ", line[col]) == 0)
			throw_error("InvalidMapError : invalid character!");
		col++;
	}
}

void	valid_map(t_map_info *map_info)
{
	int	row;

	row = 0;
	while (row < map_info->height)
	{
		valid_character(map_info, row);
		valid_edge_wall(map_info, row);
		valid_inner_wall(map_info, row);
		row++;
	}
	if (map_info->player_x == -1)
		throw_error("InvalidMapError : player must exist only one");
}
