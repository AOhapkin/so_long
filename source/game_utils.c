#include "so_long.h"

void	win_game(t_game *game)
{
	ft_printf("Well done! You won with %d moves!\n", game->moves);
	ft_exit(game);
}

void	ft_move(t_game *game, int y, int x)
{
	char	move;

	move = game->map[y][x];
	if (move == 'E' && game->coins == 0)
		win_game(game);
	if (move == '1' || (move == 'E' && game->coins > 0))
		return ;
	else if (move == '0')
	{
		put_xpm_image(game->x * SCALE, game->y * SCALE, FLOOR, game);
		put_xpm_image(x * SCALE, y * SCALE, PLAYER1, game);
	}
	else if (move == 'C')
	{
		put_xpm_image(game->x * SCALE, game->y * SCALE, FLOOR, game);
		put_xpm_image(x * SCALE, y * SCALE, PLAYER1, game);
		game->map[y][x] = '0';
		game->coins--;
	}
	game->y = y;
	game->x = x;
	ft_printf("Moves: %d\n", game->moves++);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEYRIGHT || keycode == KEYD)
		ft_move(game, game->y, game->x + 1);
	else if (keycode == KEYLEFT || keycode == KEYA)
		ft_move(game, game->y, game->x - 1);
	else if (keycode == KEYUP || keycode == KEYW)
		ft_move(game, game->y - 1, game->x);
	else if (keycode == KEYDOWN || keycode == KEYS)
		ft_move(game, game->y + 1, game->x);
	else if (keycode == 53)
		ft_exit(game);
	return (0);
}
