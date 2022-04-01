#include "so_long.h"

int	isfiletype(char *path, char *type)
{
	int	len;

	len = ft_strlen(path);
	return (ft_strncmp(path + len - ft_strlen(type), type, len) == 0);
}
