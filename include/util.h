#ifndef UTIL_H
# define UTIL_H

# include "cub3D.h"

char	*ft_get_line(int fd);
char	*ft_trim_line(char *line);

void	*ft_make_img(void *mlx_ptr, char *xpmFile);
int		ft_str_to_rgb(char *str);

#endif