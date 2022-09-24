#include "cub3D.h"
#include "error.h"
#include "libft.h"

static int	ctoi(char c)
{
	int	res;

	res = c - '0';
	return (res);
}

static int	detect_flow(int is_minus)
{
	if (is_minus == -1)
		return (0);
	else
		return (-1);
}

int	ft_get_valid_rgb(char *str)
{
	long long	res;
	long long	tmp;
	int			i;

	i = 0;
	res = 0;
	while (str[i] && ft_strchr(WHITESPACE, str[i]))
		i++;
	if (str[i] == 0)
		throw_error("Color Error : RGB value is empty");
	while (ft_isdigit(str[i]))
	{
		tmp = res * 10 + ctoi(str[i++]);
		if (tmp > 255)
			throw_error("Color Error : range of color is 0~255");
		res = tmp;
	}
	while (str[i] && ft_strchr(WHITESPACE, str[i]))
		i++;
	if (str[i] && !ft_isdigit(str[i]))
		throw_error("Color Error : R,G,B must be integer not character");
	return ((int)res);
}
