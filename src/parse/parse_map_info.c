/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_info.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:49:06 by nkim              #+#    #+#             */
/*   Updated: 2022/09/29 17:49:06 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "error.h"
#include "libft.h"
#include "util.h"

void	parse_map_info(t_map_info *map_info, int fd)
{
	char	*line;

	line = ft_trim_line_back(ft_get_line(fd));
	if (!line)
		throw_error("EmptyFileError : file is empty!");
	while (*line == '\0')
		line = ft_trim_line(ft_get_line(fd));
	while (line)
	{
		map_info->map = (char **)ft_ptrrealloc(map_info->map, map_info->height,
				map_info->height + 1);
		map_info->map[map_info->height] = line;
		map_info->height++;
		if (map_info->width < (int)ft_strlen(line))
			map_info->width = (int)ft_strlen(line);
		line = ft_trim_line_back(ft_get_line(fd));
	}
	close(fd);
}
