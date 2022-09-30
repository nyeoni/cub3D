/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_inner_wall.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:49:21 by nkim              #+#    #+#             */
/*   Updated: 2022/09/30 12:53:28 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "error.h"
#include "libft.h"

static void	check_space(char **map, int row, int col, int arrow)
{
	if (arrow == UP)
		arrow = map[row - 1][col];
	else if (arrow == DOWN)
		arrow = map[row + 1][col];
	else if (arrow == LEFT)
		arrow = map[row][col - 1];
	else if (arrow == RIGHT)
		arrow = map[row][col + 1];
	if (arrow != SPACE && arrow != WALL)
		throw_error("InvalidMapError : space must be surrounded by wall!");
}

static void	check_side_space(char **map, int row, int col)
{
	int	len;

	len = ft_strlen(map[row]);
	if (col == 0)
		check_space(map, row, col, RIGHT);
	else if (col == len - 1)
		check_space(map, row, col, LEFT);
	else
	{
		check_space(map, row, col, LEFT);
		check_space(map, row, col, RIGHT);
	}
}

void	valid_inner_wall(char *line, char **map, int height, int row)
{
	int		col;

	col = 0;
	while (line[col])
	{
		if (line[col] == SPACE)
		{
			if (row == 0)
				check_space(map, row, col, DOWN);
			else if (row == height - 1)
				check_space(map, row, col, UP);
			else
			{
				check_space(map, row, col, UP);
				check_space(map, row, col, DOWN);
			}
			check_side_space(map, row, col);
		}
		col++;
	}
}
