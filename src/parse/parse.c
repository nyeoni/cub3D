#include "cub3D.h"
#include "error.h"
#include "libft.h"
#include "util.h"
#include <fcntl.h>

static void	valid_extension(char *fileName)
{
	char	*extension;
	int		diff;

	extension = ft_strrchr(fileName, '.');
	if (!extension)
		throw_error("ExtensionError : file extension is not .cub file!");
	diff = ft_strncmp(extension, ".cub", 5);
	if (diff)
		throw_error("ExtensionError : file extension is not .cub file!");
}

static void	read_map_info(int fd, t_map_info *map_info)
{
	char	*line;

	if (!line)
		throw_error("EmptyFileError : file is empty!");
	while (line)
	{
		map_info->map = (char **)ft_ptrrealloc(map_info->map, map_info->height,
				map_info->height + 1);
		map_info->map[map_info->height] = line;
		map_info->height++;
		if (map_info->width < ft_strlen(line))
			map_info->width = ft_strlen(line);
		line = ft_get_line(fd);
	}
	close(fd);
}

static void	read_graphic_info(int fd, t_graphic_info *graphic_info)
{
	char	*line;
	char	*tmp;

	tmp = ft_get_line(fd);
	if (!line)
		throw_error("EmptyFileError : file is empty!");
	// trim
	line = ft_strtrim(tmp, " \t\v\f\r");
	free(tmp);
	while (*line == '\0')
	{
		tmp = ft_get_line(fd);
		line = ft_strtrim(line, " \t\v\f\r");
		free(tmp);
	}
	// graphic_info
	if (ft_strncmp(line, "NO", 2))
	{
	}
	else if (ft_strncmp(line, "SO", 2))
	{
	}
	else if (ft_strncmp(line, "WE", 2))
	{
	}
	else if (ft_strncmp(line, "EA", 2))
	{
	}
}
void	parse(char *filename, t_game *game)
{
	int fd;

	valid_extension(filename);
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		throw_error("FileError : error when open file");
	// read_graphic_info(fd, &game->graphic_info);
	read_map_info(fd, &game->map_info);
	// valid_wall()
}