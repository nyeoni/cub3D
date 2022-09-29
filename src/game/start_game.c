/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:48:37 by nkim              #+#    #+#             */
/*   Updated: 2022/09/29 17:48:38 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "draw.h"
#include "game.h"
#include "math.h"
#include "raycast.h"
#include "util.h"

void	start_game(t_game *game)
{
	game->gl.win_ptr = mlx_new_window(game->gl.mlx_ptr,
										WIN_WIDTH,
										WIN_HEIGHT,
										"minimap");
	draw_game(game);
	draw_minimap(game);
}