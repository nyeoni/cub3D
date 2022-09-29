#ifndef DRAW_H
# define DRAW_H

# include "mlx.h"

typedef struct s_game		t_game;
typedef struct s_state		t_state;
typedef struct s_img_info	t_img_info;
typedef struct s_gl			t_gl;
typedef struct s_point		t_point;
typedef struct s_ray		t_ray;

void						draw_minimap_bg(t_game *game);
void						draw_minimap_player(t_game *game);
void						draw_line(t_point *sp, t_point *ep, t_gl *gl);
void						draw_square(t_point *sp, int size, int color,
								t_gl *gl);
void						draw_dir_line(t_state *state, int block, t_gl *gl);
void						draw_ray(t_game *game, t_ray *ray);
void						draw_minimap(t_game *game);
void						draw_game(t_game *game);
void						draw_pixel(t_img_info *img_info, int x, int y,
								int color);

#endif