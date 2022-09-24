#ifndef UTIL_H
# define UTIL_H

# include "cub3D.h"

char	*ft_get_line(int fd);
char	*ft_trim_line(char *line);
char	*ft_trim_line_back(char *line);
char	*ft_strtrim_back(char const *s1, char const *set);

void	*ft_make_img(void *mlx_ptr, char *xpmFile);
int		ft_str_to_rgb(char *str);
char	*ft_strtrim_back(char const *s1, char const *set);
void	ft_put_img(t_gl *gl, void *img, int x, int y);

#endif