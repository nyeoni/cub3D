#ifndef HANDLER_H
# define HANDLER_H

typedef struct s_game	t_game;

typedef struct s_game	t_game;
typedef struct s_state	t_state;

typedef enum e_event
{
	KeyPress = 2,
	KeyRelease = 3,
	KeyExit = 17
}						t_event;

typedef enum e_keycode
{
	KEY_NONE = -1,
	KEY_ESC = 53,
	KEY_W = 13,
	KEY_S = 1,
	KEY_D = 2,
	KEY_A = 0,
	KEY_LD = 123,
	KEY_RD = 124
}						t_keycode;

int						keypress_handler(int key, t_game *game);
int						close_game(t_game *game);
int						check_wall_collision(t_point next_pos, t_state *state,
							t_game *game);

#endif