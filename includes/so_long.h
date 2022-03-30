#ifndef
# define SO_LONG
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "mlx.h"

# define VALID_MAP_SYMBOL	"10ECP"
# define WALL			'1'
# define SPACE			'0'
# define EXIT			'E'
# define COLLECTIBLE	'C'
# define PLAYER			'P'

struct s_map
{
	size_t	width;
	size_t	height;
};

#endif