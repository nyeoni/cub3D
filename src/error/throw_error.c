/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   throw_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hannkim <hannkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:48:31 by nkim              #+#    #+#             */
/*   Updated: 2022/09/29 20:16:34 by hannkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	throw_error(char *message)
{
	ft_putstr_fd("\033[31mError\n\033[0m", 2);
	ft_putstr_fd(message, 2);
	exit(EXIT_FAILURE);
}
