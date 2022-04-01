#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "mlx.h"
# include "libft.h"

# define GNL_BUFFER_SIZE	42
# define GNL_DIVIDER	'\n'
# define GNL_MAX_FD		256

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

char	*get_next_line(int fd);
void	free_tmp(char *tmp_for_freeing);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strdup(const char *str);

void	init_map(char *file_path, t_game *game);
void	validate_map(t_game *game);

#endif