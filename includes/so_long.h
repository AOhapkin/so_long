#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include "mlx.h"
# include "libft.h"

# define GNL_BUFFER_SIZE	42
# define GNL_DIVIDER	'\n'
# define GNL_MAX_FD		256

# define SCALE 48
# define WALL "./img/bush.xpm"
# define FLOOR "./img/grass.xpm"
# define COIN "./img/carrot.xpm"
# define PLAYER1 "./img/sheep1.xpm"
# define PLAYER2 "./img/sheep2.xpm"
# define PLAYER3 "./img/sheep3.xpm"
# define PLAYER4 "./img/sheep4.xpm"
# define ENEMY1 "./img/wolf1.xpm"
# define ENEMY2 "./img/wolf2.xpm"
# define ENEMY3 "./img/wolf3.xpm"
# define EXIT "./img/exit.xpm"
# define KEYUP 13
# define KEYDOWN 1
# define KEYRIGHT 2
# define KEYLEFT 0
# define KEYD 124
# define KEYA 123
# define KEYW 126
# define KEYS 125

typedef struct s_game
{
	void		*mlx;
	void		*win;
	void		*img;
	int			width;
	int			height;
	char		**map;
	int			moves;
	int			coins;
	int			players;
	int			enemy;
	int			exit;
	int			x;
	int			y;
	t_list		*enemies;
}	t_game;

typedef struct s_enemy
{
	int				x;
	int				y;
	int				flag;
}					t_enemy;

void	parse_map(char *argv, t_game *game);
void	read_file(char *argv, t_game *game);
void	put_image(int x, int y, char c, t_game *game);
void	draw_map(t_game *game);
void	put_xpm_image(int x, int y, const char *file, t_game *game);
void	ft_error_exit(char *error, t_game *game);
void	ft_map_eror(t_game *game, int exit, int unknown);
void	check_chars(t_game *game);
void	choose_player_position(t_game *game);
void	check_walls(t_game *game);
void	add_enemy(t_game *game);
void	meet_enemy(t_game *game);
void	free_enemy(void *content);

int		get_next_line_fd(int fd, char **line);
int		display_score(t_game *game);
int		key_hook(int keycode, t_game *game);
int		ft_exit(t_game *game);
int		animation(t_game *game);

#endif