#include "so_long.h"

void	player_init(t_game *game, int x, int y)
{
	game->player.x = x;
	game->player.y = y;
	game->player.x_origin = x;
	game->player.y_origin = y;
	game->player.moves = 0;
	game->player.collects = 0;
	game->player.previous = FLOOR;
	game->player.direction = KEY_DOWN;
}

void	player_move_up(t_game *game)
{
	int		x;
	int		y;

	x = game->player.x;
	y = game->player.y;
	game->player.direction = KEY_UP;
	if (game->map.tiles[y - 1][x] == EXIT)
		game_end(game);
	else if (game->map.tiles[y - 1][x] != WALL)
	{
		game->map.tiles[y][x] = game->player.previous;
		if (game->map.tiles[y - 1][x] == COLLECTIBLE)
		{
			game->player.collects++;
			game->player.previous = FLOOR;
		}
		game->map.tiles[y - 1][x] = PLAYER;
		game->player.y--;
		game->player.moves++;
	}
}

void	player_move_down(t_game *game)
{
	int		x;
	int		y;

	x = game->player.x;
	y = game->player.y;
	game->player.direction = KEY_DOWN;
	if (game->map.tiles[y + 1][x] == EXIT)
		game_end(game);
	else if (game->map.tiles[y + 1][x] != WALL)
	{
		game->map.tiles[y][x] = game->player.previous;
		if (game->map.tiles[y + 1][x] == COLLECTIBLE)
		{
			game->player.collects++;
			game->player.previous = FLOOR;
		}
		game->map.tiles[y + 1][x] = PLAYER;
		game->player.y++;
		game->player.moves++;
	}
}

void	player_move_left(t_game *game)
{
	int		x;
	int		y;

	x = game->player.x;
	y = game->player.y;
	game->player.direction = KEY_LEFT;
	if (game->map.tiles[y][x - 1] == EXIT)
		game_end(game);
	else if (game->map.tiles[y][x - 1] != WALL)
	{
		game->map.tiles[y][x] = game->player.previous;
		if (game->map.tiles[y][x - 1] == COLLECTIBLE)
		{
			game->player.collects++;
			game->player.previous = FLOOR;
		}
		game->map.tiles[y][x - 1] = PLAYER;
		game->player.x--;
		game->player.moves++;
	}
}

void	player_move_right(t_game *game)
{
	int		x;
	int		y;

	x = game->player.x;
	y = game->player.y;
	game->player.direction = KEY_RIGHT;
	if (game->map.tiles[y][x + 1] == EXIT)
		game_end(game);
	else if (game->map.tiles[y][x + 1] != WALL)
	{
		game->map.tiles[y][x] = game->player.previous;
		if (game->map.tiles[y][x + 1] == COLLECTIBLE)
		{
			game->player.collects++;
			game->player.previous = FLOOR;
		}
		game->map.tiles[y][x + 1] = PLAYER;
		game->player.x++;
		game->player.moves++;
	}
}
