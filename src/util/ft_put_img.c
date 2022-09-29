/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/29 23:16:56 by nkim              #+#    #+#             */
/*   Updated: 2022/09/29 16:06:32 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "mlx.h"

void	ft_put_img(t_gl *gl, void *img, int x, int y)
{
	mlx_put_image_to_window(gl->mlx_ptr, gl->win_ptr, img, x, y);
}
