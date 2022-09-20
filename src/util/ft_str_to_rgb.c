#include "error.h"
#include "libft.h"
#include <stdio.h>

// static int	get_rgb_num(char *str)
// {
// 	int	rgb;
// throw_error("RGBError : Wrong value of rgb is given.");
// 	rgb = ft_atoi(str);
// 	if (rgb == 0 && )
// 	if (rgb < 0 || rgb > 255)
// 		return (0);
// }

int	ft_str_to_rgb(char *str)
{
	char **arr;
	int rgb;

	rgb = 0;
	arr = ft_split(str, ',');
	rgb += ft_atoi(arr[0]) << 16;
	rgb += ft_atoi(arr[1]) << 8;
	rgb += ft_atoi(arr[2]);
	printf("color: %s\n", str);
	printf("atoi: %d\n", ft_atoi(str));
	printf("rgb: %x\n", rgb);
	return (rgb);
}