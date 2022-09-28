#ifndef INIT_H
# define INIT_H

# include "cub3D.h"

void	init(t_game *game);
void	init_state(t_state *state);
void	init_map_info(t_map_info *map_info);
void	init_graphic_info(t_graphic_info *graphic_info, t_gl *gl);

#endif