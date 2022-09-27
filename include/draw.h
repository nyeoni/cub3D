#ifndef DRAW_H
# define DRAW_H

# include "cub3D.h"

void	draw_minimap_bg(t_game *game);
void	draw_minimap_player(t_game *game);
void	draw_line(t_point *sp, t_point *ep, t_gl *gl);
void	draw_dir_line(t_state *state, int block, t_gl *gl);

#endif