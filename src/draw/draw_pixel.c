#include "cub3D.h"

void	draw_pixel(t_img_info *img_info, int x, int y, int color)
{
	int	color_byte;
	int	pixel;

	color_byte = img_info->bpp / 8;
	pixel = (y * img_info->size_line) / color_byte + x;
	*(img_info->buf + pixel) = color;
}
