/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trim_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:50:06 by nkim              #+#    #+#             */
/*   Updated: 2022/09/29 17:50:06 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "util.h"

char	*ft_trim_line_back(char *line)
{
	char	*result;

	result = ft_strtrim_back(line, WHITESPACE);
	free(line);
	return (result);
}

char	*ft_trim_line(char *line)
{
	char	*result;

	result = ft_strtrim(line, WHITESPACE);
	free(line);
	return (result);
}
