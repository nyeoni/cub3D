#ifndef INIT_H
# define INIT_H

typedef struct s_game			t_game;
typedef struct s_state			t_state;
typedef struct s_map_info		t_map_info;
typedef struct s_graphic_info	t_graphic_info;
typedef struct s_gl				t_gl;

void							init(t_game *game);
void							init_state(t_state *state);
void							init_map_info(t_map_info *map_info);
void	init_graphic_info(t_graphic_info *graphic_info,
						t_gl *gl);

#endif