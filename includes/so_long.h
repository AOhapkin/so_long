#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include "libft.h"

# define SCALE 64
# define MAP_FILE_TYPE ".ber"

# define WALL_IMG "./img/wall.xpm"
# define FLOOR_IMG "./img/floor.xpm"
# define COIN_IMG "./img/fish.xpm"
# define PLAYER_IMG "./img/player.xpm"
# define EXIT_IMG "./img/house.xpm"

# define KEY_UP 13
# define KEY_LEFT 0
# define KEY_DOWN 1
# define KEY_RIGHT 2

# define KEY_W 126
# define KEY_A 123
# define KEY_S 125
# define KEY_D 124

# define KEY_ESC 53

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	int			width;
	int			height;
	char		**map;
	int			moves_counter;
	int			coins;
	int			players;
	int			exit;
	int			x;
	int			y;
}	t_game;

void	init_game(t_game *game);
void	validate_chars(t_game *game);
void	validate_walls(t_game *game);
void	parse_map(char *argv, t_game *game);
void	read_file(char *argv, t_game *game);
void	ft_put_map(t_game *game);
void	ft_game_error(char *error, t_game *game);
int		ft_free_exit(t_game *game);
void	put_xpm_image(int x, int y, const char *file, t_game *game);
int		get_next_line_fd(int fd, char **line);
int		key_hook(int keycode, t_game *game);

#endif