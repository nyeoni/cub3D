#include "cub3D.h"
#include "error.h"
#include "libft.h"
#include "parse.h"

static void	valid_character(t_map_info *map_info, int row, int *player_cnt)
{
	char	*line;
	int		col;

	line = map_info->map[row];
	col = 0;
	while (line[col])
	{
		if (ft_strchr("NSEW", line[col]))
			(*player_cnt)++;
		else if (ft_strchr("01 ", line[col]) == 0)
			throw_error("InvalidMapError : invalid character!");
		col++;
	}
}

void	valid_map(t_map_info *map_info)
{
	int	row;
	int	player_cnt;

	row = 0;
	player_cnt = 0;
	while (row < map_info->height)
	{
		valid_character(map_info, row, &player_cnt);
		valid_edge_wall(map_info, row);
		valid_inner_wall(map_info, row);
		row++;
	}
	if (player_cnt != 1)
		throw_error("InvalidMapError : player must exist only one!");
}
