// cub3D structure
#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>

# define IMG_PATH "./img/"

# define WHITESPACE " \t\v\f\r\n"

# define DIR_TEXTURE_CNT 4
# define COLOR_CNT 2
# define IMG_SIZE 64

# define WIN_WIDTH 1280
# define WIN_HEIGHT 520

typedef struct s_map_info
{
	char			**map;
	int				width;
	int				height;
}					t_map_info;

typedef enum e_dir
{
	NO,
	SO,
	WE,
	EA
}					t_dir;

typedef enum e_color_type
{
	F,
	C
}					t_color_type;

typedef struct s_graphic_info
{
	void			*texture[4];
	int				color[2];
}					t_graphic_info;

typedef struct s_game
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_map_info		map_info;
	t_graphic_info	graphic_info;

}					t_game;

#endif