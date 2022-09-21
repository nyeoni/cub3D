#include "parse.h"

void	parse_map_info(t_map_info *map_info, int fd)
{
	char *line;

	// ft_trim_line_back 으로 바꾸기 @hannkim
	// line = ft_trim_line(ft_get_line(fd));

	line = ft_get_line(fd);
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
		if (map_info->width < ft_strlen(line))
			map_info->width = ft_strlen(line);
		line = ft_get_line(fd);
	}
	close(fd);
}