/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_graphic_info.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:49:03 by nkim              #+#    #+#             */
/*   Updated: 2022/09/30 12:36:59 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "error.h"
#include "libft.h"
#include "mlx.h"
#include "util.h"

static void	parse_color(int *color, char *line, int *check)
{
	t_color_type	type;
	char			*str;

	type = 0;
	if (!ft_strncmp(line, "F", 1))
		type = F;
	else if (!ft_strncmp(line, "C", 1))
		type = C;
	else
		throw_error("UnknownError : Unknown line is given.");
	str = ft_strtrim(line + 2, WHITESPACE);
	if (check[type + DIR_TEXTURE_CNT] == 1)
		throw_error("GraphicError : Duplicate graphic identifier!");
	color[type] = ft_str_to_rgb(str);
	check[type + DIR_TEXTURE_CNT] = 1;
	free(str);
	free(line);
}

static void	parse_texture_color(t_graphic_info *graphic_info, char *line,
	void *mlx_ptr, int *check)
{
	t_dir		dir;
	t_img_info	img_info;

	if (!ft_strncmp(line, "NO", 2))
		dir = NO;
	else if (!ft_strncmp(line, "SO", 2))
		dir = SO;
	else if (!ft_strncmp(line, "WE", 2))
		dir = WE;
	else if (!ft_strncmp(line, "EA", 2))
		dir = EA;
	else
	{
		parse_color(graphic_info->color, line, check);
		return ;
	}
	if (check[dir] == 1)
		throw_error("GraphicError : Duplicate graphic identifier!");
	graphic_info->texture[dir] = ft_make_img(mlx_ptr,
			ft_strtrim(line + 2, WHITESPACE));
	img_info.buf = (unsigned *)mlx_get_data_addr(graphic_info->texture[dir],
			&img_info.bpp, &img_info.size_line, &img_info.endian);
	graphic_info->texture_info[dir] = img_info;
	check[dir] = 1;
	free(line);
}

static void	valid_graphic_info(int *check)
{
	int	cnt;
	int	i;

	i = 0;
	while (i < DIR_TEXTURE_CNT)
	{
		if (check[i++] != 1)
			throw_error("TextureError : Can't find all texture.");
	}
	cnt = i;
	while (i < cnt + COLOR_CNT)
	{
		if (check[i++] != 1)
			throw_error("ColorError : Can't find all color.");
	}
}

void	parse_graphic_info(t_graphic_info *graphic_info, int fd, void *mlx_ptr)
{
	char	*line;
	int		cnt;
	int		check[DIR_TEXTURE_CNT + COLOR_CNT];

	line = ft_trim_line(ft_get_line(fd));
	if (!line)
		throw_error("EmptyFileError : file is empty!");
	cnt = 0 - 1;
	while (++cnt < DIR_TEXTURE_CNT + COLOR_CNT)
		check[cnt] = 0;
	cnt = 0 -1;
	while (++cnt < DIR_TEXTURE_CNT + COLOR_CNT)
	{
		while (*line == '\0')
		{
			free(line);
			line = ft_trim_line(ft_get_line(fd));
		}
		parse_texture_color(graphic_info, line, mlx_ptr, check);
		line = ft_trim_line(ft_get_line(fd));
	}
	if (line)
		free(line);
	valid_graphic_info(check);
}
