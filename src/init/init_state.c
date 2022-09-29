/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_state.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:48:53 by nkim              #+#    #+#             */
/*   Updated: 2022/09/29 20:20:33 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_state(t_state *state)
{
	state->pos.x = 0;
	state->pos.y = 0;
	state->dir.x = 0;
	state->dir.y = 0;
	state->plane.x = 0;
	state->plane.y = 0;
}
