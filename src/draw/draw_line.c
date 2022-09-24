#include "draw.h"
#include "math.h"

void	draw_line(t_point *sp, t_point *ep, t_gl *gl)
{
	double m;
	double k;
	int max_x;
	int x;
	int y;

	m = (sp->y - ep->y) / (sp->x - ep->x);
	k = m * (sp->x) - (sp->y);
	if (sp->x < ep->x)
	{
		x = sp->x;
		max_x = ep->x;
	}
	else
	{
		x = ep->x;
		max_x = sp->x;
	}
	while (x <= max_x)
	{
		y = floor(m * x + k);
		mlx_pixel_put(gl->mlx_ptr, gl->win_ptr, x, y, 0xff0000);
		x++;
	}
}