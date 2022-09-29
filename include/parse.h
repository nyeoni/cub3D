#ifndef PARSE_H
# define PARSE_H

typedef struct s_game			t_game;
typedef struct s_state			t_state;
typedef struct s_map_info		t_map_info;

typedef struct s_graphic_info	t_graphic_info;
void							parse(char *filename, t_game *game);
void							valid_extension(char *fileName);
void							parse_map_info(t_map_info *map_info, int fd);
void	parse_graphic_info(t_graphic_info *graphic_info,
						int fd,
						void *mlx_ptr);
void	parse_state(t_state *state,
					t_map_info *map_info);

void	set_dir(t_state *state, double dir_x, double dir_y);
void	set_plane(t_state *state);
void	set_pos(t_state *state, double x, double y);

void	valid_map(t_game *game);
void	valid_edge_wall(t_map_info *map_info, int row);
void	valid_inner_wall(t_map_info *map, int row);

#endif