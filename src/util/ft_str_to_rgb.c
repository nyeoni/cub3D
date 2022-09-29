/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_to_rgb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:49:59 by nkim              #+#    #+#             */
/*   Updated: 2022/09/29 20:28:10 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include "util.h"

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
	char	**arr;
	int		rgb;

	rgb = 0;
	arr = ft_split(str, ',');
	check_split(arr);
	rgb += ft_get_valid_rgb(ft_trim_line(arr[0])) << 16;
	rgb += ft_get_valid_rgb(ft_trim_line(arr[1])) << 8;
	rgb += ft_get_valid_rgb(ft_trim_line(arr[2]));
	return (rgb);
}
