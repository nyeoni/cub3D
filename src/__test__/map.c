#include "cub3D.h"
#include "libft42.h"
#include <stdio.h>

void	print_info(t_map_info *info)
{
	char **map = info->map;

	printf("width: %d, height: %d\n", info->width, info->height);
	for (int i = 0; i < info->height; i++)
	{
		printf("%s\n", map[i]);
	}
}