#include "cub3D.h"
#include "libft42.h"
#include <stdio.h>

static void	print_map_info(t_map_info *map_info)
{
	char	**map;

	map = map_info->map;
	printf("width: %d, height: %d\n", map_info->width, map_info->height);
	for (int i = 0; i < map_info->height; i++)
	{
		printf("%s\n", map[i]);
	}
}

static void	print_graphic_info(t_graphic_info *g_info)
{
}

void	print_info(t_game *game)
{
	print_map_info(&game->map_info);
}