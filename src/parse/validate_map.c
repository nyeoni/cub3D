#include "cub3D.h"
#include "libft.h"
#include "error.h"

void	validate_character(t_map_info	*map_info)
{
	int 	i;
	int		j;
	int 	player_cnt;

	i = 0;
	j = 0;
	player_cnt = 0;
	while (i < map_info->height)
	{
		while (j < map_info->width)
		{
			if (ft_strchr("NSEW", map_info->map[i][j]))
				player_cnt++;
			else if (ft_strchr("01 ", map_info->map[i][j]) == 0)
				throw_error("InvalidMapError : invalid character!");
			j++;
		}
		i++;
	}
	if (player_cnt != 1)
		throw_error("InvalidMapError : too many player!");
}

void	validate_map(t_game *game)
{
	validate_character(&game->map_info);
	// validate_wall();
}