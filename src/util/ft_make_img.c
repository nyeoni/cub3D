#include "cub3D.h"
#include "error.h"
#include "libft.h"
#include "mlx.h"
#include <stdio.h>
void	*ft_make_img(void *mlx_ptr, char *xpmFile)
{
	char	*path;
	void	*img;
	int		width;
	int		height;

	if (!ft_strncmp(xpmFile, "./", 2) || !ft_strncmp(xpmFile, "../", 3))
		path = xpmFile;
	else
		path = ft_strjoin(IMG_PATH, xpmFile);
	img = mlx_xpm_file_to_image(mlx_ptr, path, &width, &height);
	free(path);
	if (!img)
	{
		throw_error("XPM Error : check ASSET_PATH or fileName");
	}
	return (img);
}
