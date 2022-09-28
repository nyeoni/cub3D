#include "init.h"
#include "libft.h"
#include "util.h"

void	init_map_info(t_map_info *map_info)
{
	map_info->map = (char **)ft_calloc(1, sizeof(char *));
	map_info->width = 0;
	map_info->height = 0;
}

void	init_graphic_info(t_graphic_info *graphic_info)
{
	int	i;

	i = 0 - 1;
	while (++i < DIR_TEXTURE_CNT)
		graphic_info->texture[i] = NULL;
	i = 0 - 1;
	while (++i < COLOR_CNT)
		graphic_info->bg_color[i] = -1;
}

void	init_minimap_info(t_mini_graphic_info *minimap_info, t_gl *gl)
{
	minimap_info->wall = ft_make_img(gl->mlx_ptr, "wall.xpm");
	minimap_info->space = ft_make_img(gl->mlx_ptr, "space.xpm");
}