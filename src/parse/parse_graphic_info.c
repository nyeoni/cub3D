#include "parse.h"

static void	parse_texture(void **texture, char *line, void *mlx_ptr, int *check)
{
	t_dir	dir;

	printf("%s\n", line);
	if (!ft_strncmp(line, "NO", 2))
		dir = NO;
	else if (!ft_strncmp(line, "SO", 2))
		dir = SO;
	else if (!ft_strncmp(line, "WE", 2))
		dir = WE;
	else if (!ft_strncmp(line, "EA", 2))
		dir = EA;
	else
		throw_error("UnknownError : Unknown line is given.");
	texture[dir] =
		ft_make_img(mlx_ptr, ft_strtrim(line + 2, WHITESPACE));
	check[dir] = 1;
	free(line);
}

static void	parse_color(int *color, char *line, int *check)
{
	t_color_type	type;

	if (ft_strncmp(line, "F", 1))
		type = F;
	else if (ft_strncmp(line, "C", 1))
		type = C;
	else
		throw_error("UnknownError : Unknown line is given.");
	color[type] =
		ft_str_to_rgb(ft_strtrim(line + 2, WHITESPACE));
	check[type + DIR_TEXTURE_CNT] = 1;
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
	char *line;
	int cnt;
	int check[DIR_TEXTURE_CNT + COLOR_CNT];

	line = ft_trim_line(ft_get_line(fd));
	if (!line)
		throw_error("EmptyFileError : file is empty!");
	cnt = 0 - 1;
	while (++cnt < DIR_TEXTURE_CNT)
	{
		while (*line == '\0')
			line = ft_trim_line(ft_get_line(fd));
		parse_texture(graphic_info->texture, line, mlx_ptr, check);
		line = ft_trim_line(ft_get_line(fd));
	}
	cnt = 0 - 1;
	while (++cnt < COLOR_CNT)
	{
		while (*line == '\0')
			line = ft_trim_line(ft_get_line(fd));
		parse_color(graphic_info->color, line, check);
		line = ft_trim_line(ft_get_line(fd));
	}
	valid_graphic_info(check);
}