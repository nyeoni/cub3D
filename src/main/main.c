/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 12:43:47 by nkim              #+#    #+#             */
/*   Updated: 2022/09/16 13:52:10 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	printf("hi");
	void *mlx_ptr = mlx_init();
	void *result = mlx_new_window(mlx_ptr, 1024, 512, "Raycasting-practice");
	printf("ptr: %p\n", result);
}