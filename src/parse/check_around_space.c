#include "error.h"

/*
	left	: map[row][col - 1]
	right	: map[row][col + 1]
	up		: map[row - 1][col]
	down	: map[row + 1][col]
*/
void	check_left(char **map, int row, int col)
{
	char	left;

	left = map[row][col - 1];
	if (left != ' ' && left != '1')
		throw_error("InvalidMapError : space must be surrounded by wall!");
}

void	check_right(char **map, int row, int col)
{
	char	right;

	right = map[row][col + 1];
	if (right != ' ' && right != '1')
		throw_error("InvalidMapError : space must be surrounded by wall!");
}

void	check_up(char **map, int row, int col)
{
	char	up;

	up = map[row - 1][col];
	if (up != ' ' && up != '1')
		throw_error("InvalidMapError : space must be surrounded by wall!");
}

void	check_down(char **map, int row, int col)
{
	char	down;

	down = map[row + 1][col];
	if (down != ' ' && down != '1')
		throw_error("InvalidMapError : space must be surrounded by wall!");
}
