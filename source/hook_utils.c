#include "so_long.h"

int	hook_key_press(int keycode, t_game *game)
{
	if (keycode == KEY_UP)
		player_move_up(game);
	else if (keycode == KEY_LEFT)
		player_move_left(game);
	else if (keycode == KEY_DOWN)
		player_move_down(game);
	else if (keycode == KEY_RIGHT)
		player_move_right(game);
	else if (keycode == KEY_RESET)
		game_reset(game);
	else if (keycode == KEY_EXIT)
		game_exit(game);
	return (0);
}

int	hook_close_window(int keycode, t_game *game)
{
	(void)keycode;
	(void)game;
	exit(0);
	return (0);
}

void	hook_init(t_game *game)
{
	mlx_key_hook(game->window, hook_key_press, game);
	mlx_hook(game->window, 17, 0, hook_close_window, game);
}
