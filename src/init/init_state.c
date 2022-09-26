#include "init.h"

void	init_state(t_state *state)
{
	state->pos.x = 0;
	state->pos.y = 0;
	state->dir.x = 0;
	state->dir.y = 0;
	state->plane.x = 0;
	state->plane.y = 0;
}