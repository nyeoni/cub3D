#include "gnl.h"
#include "libft.h"

char	*ft_get_line(int fd)
{
	char *line;
	char eol;
	int len;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	len = ft_strlen(line);
	eol = line[len - 1];
	if (eol == '\n')
		line[len - 1] = 0;
	return (line);
}