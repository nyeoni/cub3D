/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:48:34 by nkim              #+#    #+#             */
/*   Updated: 2022/09/29 20:19:14 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "mlx.h"
#include <stdlib.h>

int	close_game(t_game *game)
{
	mlx_destroy_window(game->gl.mlx_ptr, game->gl.win_ptr);
	exit(SUCCESS);
}
