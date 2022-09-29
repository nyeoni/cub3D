/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_rgb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:49:59 by nkim              #+#    #+#             */
/*   Updated: 2022/09/29 23:44:40 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include "util.h"

static void free_arr(char **arr, int count) {
	int i;

	i = -1;
	while (++i < count)
		free(arr[i]);
	free(arr);
}

static void	check_split(char **arr)
{
	int	count;

	count = 0;
	while (arr[count])
		count++;
	if (count != 3)
	{
		free_arr(arr, count);
		throw_error("ColorError : R, G, B is needed");
	}
}

int	ft_str_to_rgb(char *str)
{
	char	**arr;
	int		rgb;

	rgb = 0;
	arr = ft_split(str, ',');
	check_split(arr);
	rgb += ft_get_valid_rgb(ft_trim_line(arr[0])) << 16;
	rgb += ft_get_valid_rgb(ft_trim_line(arr[1])) << 8;
	rgb += ft_get_valid_rgb(ft_trim_line(arr[2]));
	free(arr);
	return (rgb);
}
