#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "mlx.h"
# include "libft.h"

# define VALID_MAP_SYMBOLS	"10ECP"
# define WALL			'1'
# define SPACE			'0'
# define EXIT			'E'
# define COLLECTIBLE	'C'
# define PLAYER			'P'

typedef struct s_map
{
	char	*map_file;
	char	**grid_current;
	char	**grid_initial;
	size_t	width;
	size_t	height;
	size_t	players;
	size_t	collectibles;
	size_t	exits;
}		t_map;

typedef struct s_game
{
	t_map	map;
}		t_game;

void	init_map(char *file_path, t_game *game);
void	validate_map(t_game *game);

#endif