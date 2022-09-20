/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 19:04:18 by nkim              #+#    #+#             */
/*   Updated: 2022/09/20 12:02:07 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "error.h"
#include "libft.h"
#include "mlx.h"
#include <stdio.h>
void	*ft_make_img(void *mlx_ptr, char *xpmFile)
{
	char	*path;
	void	*img;
	int		width;
	int		height;

	if (!ft_strncmp(xpmFile, "./", 2) || !ft_strncmp(xpmFile, "../", 3))
		path = xpmFile;
	else
		path = ft_strjoin(IMG_PATH, xpmFile);
	img = mlx_xpm_file_to_image(mlx_ptr, path, &width, &height);
	free(path);
	if (!img)
	{
		throw_error("XPM Error : check ASSET_PATH or fileName");
	}
	else if (!(width == IMG_SIZE && height == IMG_SIZE))
		throw_error("TILE SIZE Error : incorrect tile size");
	return (img);
}
