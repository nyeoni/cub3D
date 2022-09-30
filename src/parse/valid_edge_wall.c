/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_edge_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:49:15 by nkim              #+#    #+#             */
/*   Updated: 2022/09/30 12:49:28 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "error.h"
#include "libft.h"

static void	check_edge(char *line)
{
	char	*wall;

	wall = line;
	if (*wall != WALL)
		throw_error("InvalidMapError : invalid wall of edge!");
}

static void	check_first_last_edge(char *line)
{
	char	*wall;

	wall = line;
	while (*wall)
	{
		if (*wall != WALL && *wall != SPACE)
			throw_error("InvalidMapError : invalid wall of edge!");
		wall++;
	}
}

void	valid_edge_wall(char *line, int height, int row)
{
	int		col;
	int		start;

	col = 0;
	start = ft_strchr(line, WALL) - line;
	while (col < start)
	{
		if (line[col] != SPACE)
			throw_error("InvalidMapError : invalid edge wall!");
		col++;
	}
	if (row == 0 || row == height - 1)
		check_first_last_edge(line + start);
	else
		check_edge(line + start);
}
