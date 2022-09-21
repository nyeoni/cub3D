#include "libft.h"
#include "util.h"

char	*ft_trim_line_back(char *line)
{
	char	*result;

	result = ft_strtrim_back(line, WHITESPACE);
	free(line);
	return (result);
}

char	*ft_trim_line(char *line)
{
	char	*result;

	result = ft_strtrim(line, WHITESPACE);
	free(line);
	return (result);
}
