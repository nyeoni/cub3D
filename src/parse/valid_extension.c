#include "parse.h"

void	valid_extension(char *fileName)
{
	char *extension;
	int diff;

	extension = ft_strrchr(fileName, '.');
	if (!extension)
		throw_error("ExtensionError : file extension is not .cub file!");
	diff = ft_strncmp(extension, ".cub", 5);
	if (diff)
		throw_error("ExtensionError : file extension is not .cub file!");
}