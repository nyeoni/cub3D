#include "init.h"
#include "libft.h"
#include "util.h"

void	init_map_info(t_map_info *map_info)
{
	map_info->map = (char **)ft_calloc(1, sizeof(char *));
	map_info->width = 0;
	map_info->height = 0;
}

void	init_img(t_graphic_info *graphic_info, t_gl *gl)
{
	t_img_info	img_info;

	graphic_info->img = mlx_new_image(gl->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	img_info.buf = (unsigned int *)mlx_get_data_addr(graphic_info->img,
														&img_info.bpp,
														&img_info.size_line,
														&img_info.endian);
	graphic_info->img_info = img_info;
}

void	init_graphic_info(t_graphic_info *graphic_info, t_gl *gl)
{
	int	i;

	init_img(graphic_info, gl);
	i = 0 - 1;
	while (++i < DIR_TEXTURE_CNT)
		graphic_info->texture[i] = NULL;
	return ;
	i = 0 - 1;
	while (++i < COLOR_CNT)
		graphic_info->color[i] = -1;
}
