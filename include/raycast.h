#ifndef RAYCAST_H
# define RAYCAST_H

typedef struct s_game	t_game;
typedef struct s_state	t_state;
typedef struct s_point	t_point;

typedef struct s_ray
{
	t_point				ray_dir;
	t_point				side_dist;
	t_point				delta_dist;
	int					map_x;
	int					map_y;
	double				perp_wall_dist;
	int					step_x;
	int					step_y;
	int					side;
	double				ratio;
}						t_ray;

t_ray		raycast(t_state *state, char **map, double camera_x);

void	set_ray(t_state *state,
				t_ray *ray,
				double camera_x);
void					update_ray(t_ray *ray, int axis);
void	set_perp_wall_dist(t_ray *ray,
						t_point *pos);

#endif