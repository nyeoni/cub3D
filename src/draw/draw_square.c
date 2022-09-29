#include "cub3D.h"
#include "mlx.h"

void	draw_square(t_point *sp, int size, int color, t_gl *gl)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			mlx_pixel_put(gl->mlx_ptr, gl->win_ptr, sp->x + j, sp->y + i,
					color);
			j++;
		}
		i++;
	}
}