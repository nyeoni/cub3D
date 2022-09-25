#ifndef HANDLER_H
# define HANDLER_H

# include "cub3D.h"
# include "graphic.h"

typedef struct s_game	t_game;

typedef enum e_event
{
	KeyPress = 2,
	KeyRelease = 3
}						t_event;

typedef enum e_keycode
{
	KEY_NONE = -1,
	KEY_EXIT = 17,
	KEY_W = 13,
	KEY_S = 1,
	KEY_D = 2,
	KEY_A = 0,
	KEY_LD = 123,
	KEY_RD = 124
}						t_keycode;

int						keypress_handler(int key, t_game *game);

#endif