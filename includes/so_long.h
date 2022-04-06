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

# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define MAINFRAME_INTERVAL 1000
# define ANIMEFRAME_INTERVAL 5000

#  define KEY_UP 13
#  define KEY_LEFT 0
#  define KEY_DOWN 1
#  define KEY_RIGHT 2
#  define KEY_RESET 15
#  define KEY_EXIT 53

# define IMG_SIZE 48
# define IMG_PLAYER_UP "./imgs/sprites/player-up.xpm"
# define IMG_PLAYER_LEFT "./imgs/sprites/player-left.xpm"
# define IMG_PLAYER_DOWN "./imgs/sprites/player-down.xpm"
# define IMG_PLAYER_RIGHT "./imgs/sprites/player-right.xpm"
# define IMG_WALL_TL "./imgs/sprites/wall_tl.xpm"
# define IMG_WALL_TR "./imgs/sprites/wall_tr.xpm"
# define IMG_WALL_BL "./imgs/sprites/wall_bl.xpm"
# define IMG_WALL_BR "./imgs/sprites/wall_br.xpm"
# define IMG_WALL_H "./imgs/sprites/wall_h.xpm"
# define IMG_WALL_V "./imgs/sprites/wall_v.xpm"
# define IMG_WALL_1 "./imgs/sprites/wall_1.xpm"
# define IMG_WALL_2 "./imgs/sprites/wall_2.xpm"
# define IMG_WALL_3 "./imgs/sprites/wall_3.xpm"
# define IMG_FLOOR "./imgs/sprites/floor.xpm"
# define IMG_COLLECTIBLE_1 "./imgs/sprites/collectible_1.xpm"
# define IMG_COLLECTIBLE_2 "./imgs/sprites/collectible_2.xpm"
# define IMG_COLLECTIBLE_3 "./imgs/sprites/collectible_3.xpm"
# define IMG_EXIT_OPEN "./imgs/sprites/exit_open.xpm"
# define IMG_EXIT_CLOSE "./imgs/sprites/exit_close.xpm"

# define MAP_CHARSET "01CEP"
# define MAP_FILETYPE ".ber"
# define ERR_MAP_REQUIRED "Require a map file"
# define ERR_MAP_NOT_FOUND "No such map file"
# define ERR_MAP_OPEN_FAIL "Unable to open map file"
# define ERR_MAP_INVALID_FILETYPE "The map file is not a [.ber]"
# define ERR_MAP_INVALID_CHARSET "The map contains forbidden characters"
# define ERR_MAP_INVALID_COLS "The map contains columns with different sizes"
# define ERR_MAP_INVALID_WALL "The map contains breaches in the wall"
# define ERR_MAP_INVALID "The map is not valid"
# define ERR_MAP_INVALID_COLLECTIBLE "The map does not contain an collectible"
# define ERR_MAP_INVALID_EXIT "The map does not contain an exit"
# define ERR_MAP_INVALID_PLAYER "The map must contain one player"
# define ERR_MALLOC_FAIL "The malloc failed"
# define MSG_GAME_END "Congratulations, you ate all the watermelons :D"


enum e_charset
{
	WALL = '1',
	FLOOR = '0',
	EXIT = 'E',
	PLAYER = 'P',
	COLLECTIBLE = 'C'
};

typedef struct s_image
{
	void	*ptr;
	char	*path;
	int		width;
	int		height;
}			t_image;

typedef struct s_position {
	int	x;
	int	y;
}		t_position;

typedef struct s_map
{
	char	**tiles;
	char	**snapshot;
	char	*path;
	int		cols;
	int		rows;
	int		players;
	int		collectibles;
	int		exits;
}			t_map;

typedef struct s_player
{
	int		x;
	int		y;
	int		x_origin;
	int		y_origin;
	int		direction;
	int		moves;
	int		collects;
	char	previous;
}			t_player;

typedef struct s_game
{
	char		*title;
	void		*mlx;
	void		*window;
	int			width;
	int			height;
	int			animeframe;
	t_map		map;
	t_player	player;
}				t_game;

char	*get_next_line(int fd);
void	free_tmp(char *tmp_for_freeing);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_substr(char const *str, unsigned int start, size_t len);
char	*ft_strdup(const char *str);

int		isfiletype(char *path, char *type);

void	map_init(char *path, t_game *game);
void	map_rows(t_game *game);
void	map_build(t_game *game);
void	map_free(t_game *game);
void	map_snapshot(t_game *game);
void	map_verify_wall(t_game *game);
void	map_verify_charset(t_game *game);
void	map_verify_components(t_game *game);

void	player_init(t_game *game, int x, int y);
void	player_move_up(t_game *game);
void	player_move_down(t_game *game);
void	player_move_left(t_game *game);
void	player_move_right(t_game *game);

void	game_init(char **av);
void	game_error(char *message, t_game *game);
void	game_end(t_game *game);
void	game_exit(t_game *game);
void	game_reset(t_game *game);

void	hook_init(t_game *game);
int		hook_key_press(int keycode, t_game *game);
int		hook_close_window(int keycode, t_game *game);

void	draw_tilemap(t_game *game);
void	draw_tile(t_game *game, char c, int x, int y);
void	draw_image(t_game *game, char *path, int x, int y);
void	draw_wall(t_game *game, int x, int y);
void	draw_floor(t_game *game, int x, int y);
void	draw_collectible(t_game *game, int x, int y);
void	draw_player(t_game *game, int x, int y);
void	draw_exit(t_game *game, int x, int y);
void	draw_moves_counter(t_game *game);
void	reset_moves_counter(t_game *game);

#endif