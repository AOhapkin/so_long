#include "so_long.h"

void	ft_game_error(char *error, t_game *game)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(error, 2);
	ft_free_exit(game);
}

int	ft_free_exit(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	exit(EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
	{
		ft_putendl_fd("Error. Wrong number of arguments.", 1);
		exit(EXIT_FAILURE);
	}
	init_game(&game);
	parse_map(argv[1], &game);
	game.win = mlx_new_window(game.mlx, game.width * SCALE, \
			game.height * SCALE, "so_long");
	ft_put_map(&game);
	mlx_hook(game.win, 2, 0, key_hook, &game);
	mlx_hook(game.win, 17, 0, ft_free_exit, &game);
	mlx_loop(game.mlx);
	return (0);
}
