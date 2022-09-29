/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_extension.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:49:18 by nkim              #+#    #+#             */
/*   Updated: 2022/09/29 17:49:18 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "error.h"
#include "libft.h"

void	valid_extension(char *fileName)
{
	char	*extension;
	int		diff;

	extension = ft_strrchr(fileName, '.');
	if (!extension)
		throw_error("ExtensionError : file extension is not .cub file!");
	diff = ft_strncmp(extension, ".cub", 5);
	if (diff)
		throw_error("ExtensionError : file extension is not .cub file!");
}
