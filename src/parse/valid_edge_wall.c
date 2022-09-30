/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_edge_wall.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:49:15 by nkim              #+#    #+#             */
/*   Updated: 2022/09/30 14:19:45 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "error.h"
#include "libft.h"
#include <stdio.h>

static void	check_edge(char *line, int start, int last)
{
	if (line[start] != WALL || line[last] != WALL)
		throw_error("InvalidMapError : invalid wall of edge!");
}

// static void	check_first_last_edge(char *line, int len)
static void	check_first_last_edge(char *line, int start, int last)
{
	if (start == last)
		throw_error("InvalidMapError : invalid wall of edge!");
	while (start < last)
	{
		if (line[start] != WALL && line[start] != SPACE)
			throw_error("InvalidMapError : invalid wall of edge!");
		start++;
	}
}

void	valid_edge_wall(char *line, int height, int row)
{
	int		col;
	int		start;
	int	 last;

	col = 0;
	start = ft_strchr(line, WALL) - line;
	last = ft_strrchr(line, WALL) - line;
	// if (start == last)
	// {
	// 	printf("aaa\n");
	// 	exit(1);
	// }
	while (col < start)
	{
		if (line[col] != SPACE)
			throw_error("InvalidMapError : invalid edge wall!");
		col++;
	}
	if (row == 0 || row == height - 1)
		check_first_last_edge(line, start, last);
		// check_first_last_edge(line + start, ft_strlen(line));
	else
		check_edge(line, start, last);
}
