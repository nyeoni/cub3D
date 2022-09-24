#include "error.h"
#include "libft.h"
#include "parse.h"
#include "util.h"
#include <stdio.h>

// ',' 가 2개가 아닌 경우 (arr 갯수 체크)
static void	check_split(char **arr)
{
	int	count;

	count = 0;
	while (arr[count])
		count++;
	if (count != 3)
		throw_error("ColorError : R, G, B is needed");
}

int	ft_str_to_rgb(char *str)
{
	char **arr;
	int rgb;

	rgb = 0;
	arr = ft_split(str, ',');
	check_split(arr);
	rgb += ft_get_valid_rgb(ft_trim_line(arr[0])) << 16;
	rgb += ft_get_valid_rgb(ft_trim_line(arr[1])) << 8;
	rgb += ft_get_valid_rgb(ft_trim_line(arr[2]));
	printf("rgb: %x\n", rgb);
	return (rgb);
}