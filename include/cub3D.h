// cub3D structure
#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>

typedef struct s_map_info
{
	char			**map;
	int				width;
	int				height;
}					t_map_info;

typedef struct s_graphic_info
{
	void			*north_img;
	void			*south_img;
	void			*west_img;
	void			*east_img;
	int				floor_color;
	int				ceil_color;
}					t_graphic_info;

typedef struct s_game
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_map_info		map_info;
	t_graphic_info	graphic_info;

}					t_game;

#endif