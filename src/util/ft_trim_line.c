#include "libft.h"

// ft_trim_line_back

char	*ft_trim_line(char *line)
{
	char	*result;

	result = ft_strtrim(line, " \t\v\f\r\n");
	free(line);
	return (result);
}
