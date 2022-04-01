#include "so_long.h"

void	map_verify_components(t_game *game)
{
	if (game->map.players != 1)
		game_error(ERR_MAP_INVALID_PLAYER, game);
	if (game->map.collectibles < 1)
		game_error(ERR_MAP_INVALID_COLLECTIBLE, game);
	if (game->map.exits < 1)
		game_error(ERR_MAP_INVALID_EXIT, game);
}

void	map_verify_charset(t_game *game)
{
	int		x;
	int		y;

	y = -1;
	while (++y < game->map.rows)
	{
		x = -1;
		while (++x < game->map.cols)
		{
			if (ft_strchr(MAP_CHARSET, game->map.tiles[y][x]) == 0)
				game_error(ERR_MAP_INVALID_CHARSET, game);
			if (game->map.tiles[y][x] == PLAYER)
			{
				player_init(game, x, y);
				game->map.players++;
			}
			if (game->map.tiles[y][x] == COLLECTIBLE)
				game->map.collectibles++;
			if (game->map.tiles[y][x] == EXIT)
				game->map.exits++;
		}
	}
}

void	map_verify_wall(t_game *game)
{
	int		y;
	int		x;
	int		cols;
	char	*line;

	y = -1;
	cols = 0;
	while (++y < game->map.rows)
	{
		line = game->map.tiles[y];
		cols = ft_strlen(line);
		if (y == 0)
			game->map.cols = cols;
		else if (game->map.cols != cols)
			game_error(ERR_MAP_INVALID_COLS, game);
		x = -1;
		while (++x < cols)
		{
			if (line[x] != WALL && (y == 0 || y == game->map.rows - 1))
				game_error(ERR_MAP_INVALID_WALL, game);
			if (line[x] != WALL && (x == 0 || x == cols - 1))
				game_error(ERR_MAP_INVALID_WALL, game);
		}
	}
}
