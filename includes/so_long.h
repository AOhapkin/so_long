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