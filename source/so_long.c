#include "so_long.h"

int	ft_exit(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	exit(0);
}

void	ft_error_exit(char *error, t_game *game)
{

	ft_putendl_fd(error, 1);
	ft_exit(game);
}

static void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->coins = 0;
	game->x = 0;
	game->y = 0;
	game->moves = 0;
	game->players = 0;
	game->exit = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putendl_fd("Bad arguments", 1);
		exit(EXIT_FAILURE);
	}
	init_game(&game);
	parse_map(argv[1], &game);
	game.win = mlx_new_window(game.mlx, game.width * SCALE, \
			game.height * SCALE, "so long");
	draw_map(&game);
	mlx_hook(game.win, 2, 0, key_hook, &game);
	mlx_hook(game.win, 17, 0, ft_exit, &game);
	mlx_loop(game.mlx);
	return (0);
}
