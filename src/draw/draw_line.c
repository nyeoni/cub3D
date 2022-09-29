#include "cub3D.h"
#include "math.h"
#include "mlx.h"

static void	draw_line_y(t_point *sp, t_point *ep, t_gl *gl)
{
	double	m;
	double	k;
	t_point	point;
	int		size;
	int		i;

	m = (sp->y - ep->y) / (sp->x - ep->x);
	k = sp->y - m * (sp->x);
	size = fabs(sp->y - ep->y);
	if (sp->y < ep->y)
		point.y = sp->y;
	else
		point.y = ep->y;
	i = 0;
	while (i <= size)
	{
		if (sp->x != ep->x)
			point.x = floor(((point.y + i) - k) / m + 0.5);
		else
			point.x = sp->x;
		mlx_pixel_put(gl->mlx_ptr, gl->win_ptr, point.x, point.y + i, 0xff0000);
		i++;
	}
}

static void	draw_line_x(t_point *sp, t_point *ep, t_gl *gl)
{
	double	m;
	double	k;
	t_point	point;
	int		size;
	int		i;

	m = (sp->y - ep->y) / (sp->x - ep->x);
	k = sp->y - m * (sp->x);
	size = fabs(sp->x - ep->x);
	if (sp->x < ep->x)
		point.x = sp->x;
	else
		point.x = ep->x;
	i = 0;
	while (i <= size)
	{
		point.y = floor(m * (point.x + i) + k + 0.5);
		mlx_pixel_put(gl->mlx_ptr, gl->win_ptr, point.x + i, point.y, 0xff0000);
		i++;
	}
}

void	draw_line(t_point *sp, t_point *ep, t_gl *gl)
{
	if (fabs(sp->x - ep->x) < 1)
		draw_line_y(sp, ep, gl);
	else
		draw_line_x(sp, ep, gl);
}
