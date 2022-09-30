/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_make_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:49:53 by nkim              #+#    #+#             */
/*   Updated: 2022/09/30 12:26:01 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"
#include "libft.h"
#include "mlx.h"

void	*ft_make_img(void *mlx_ptr, char *xpmFile)
{
	char	*path;
	void	*img;
	int		width;
	int		height;

	path = xpmFile;
	img = mlx_xpm_file_to_image(mlx_ptr, path, &width, &height);
	free(path);
	if (!img)
	{
		throw_error("XPM Error : check IMG_PATH or fileName");
	}
	return (img);
}
