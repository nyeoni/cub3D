/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkim <nkim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:50:02 by nkim              #+#    #+#             */
/*   Updated: 2022/09/30 15:54:20 by nkim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_first_index(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	while (s1[i])
	{
		flag = 0;
		j = 0 - 1;
		while (set[++j])
		{
			if (set[j] == s1[i])
				flag = 1;
		}
		if (!flag)
			return (i);
		i++;
	}
	return (-1);
}

static int	get_last_index(char const *s1, char const *set)
{
	int	i;
	int	j;
	int	flag;

	i = (int)ft_strlen(s1) - 1;
	while (i >= 0 && s1[i])
	{
		flag = 0;
		j = 0 - 1;
		while (set[++j])
		{
			if (set[j] == s1[i])
				flag = 1;
		}
		if (!flag)
			return (i);
		i--;
	}
	return (-1);
}

char	*ft_strtrim_back(char const *s1, char const *set)
{
	int		start;
	int		last;
	char	*res;

	if (!s1)
		return (0);
	start = get_first_index(s1, set);
	last = get_last_index(s1, set);
	if (start == -1 || last == -1)
	{
		res = (char *)ft_calloc(1, sizeof(char));
		if (!(res))
			return (0);
		return (res);
	}
	res = ft_calloc(last + 2, sizeof(char));
	if (!(res))
		return (0);
	ft_strlcpy(res, s1, last + 2);
	return (res);
}
