#include "cub3D.h"
#include "error.h"
#include "libft.h"

static void	check_edge(char *line)
{
	char	*wall;

	wall = line;
	if (*wall != '1')
		throw_error("InvalidMapError : invalid wall!");
}

static void	check_first_last_edge(char *line)
{
	char	*wall;

	wall = line;
	while (*wall)
	{
		if (*wall != '1' || *wall != ' ')
			throw_error("InvalidMapError : invalid wall!");
		wall++;
	}
}

/**
 * @brief		left side, right side wall check
 * 
 * @param start	index starting with '1' (wall character)
 */
void	valid_edge_wall(t_map_info *map_info, int row)
{
	char	*line;
	int		col;
	int		start;

	line = map_info->map[row];
	col = 0;
	start = ft_strchr(line, '1') - line;
	while (col < start)
	{
		if (line[col] != ' ')
			throw_error("InvalidMapError : invalid wall!");
		col++;
	}
	if (row == 0 || row == map_info->height - 1)
		check_first_last_edge(line);
	else
		check_edge(line);
}
