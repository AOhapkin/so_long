#include "so_long.h"

int	update_frames(t_game *game)
{
	static int	mainframe = -1;
	static int	animeframe = -1;

	if (animeframe >= ANIMEFRAME_INTERVAL)
	{
		if (game->animeframe == 1)
			game->animeframe = -1;
		game->animeframe++;
		animeframe = 0;
	}
	animeframe++;
	if (animeframe < 0)
		draw_tilemap(game);
	else if (mainframe >= MAINFRAME_INTERVAL)
	{
		draw_tilemap(game);
		mainframe = 0;
	}
	mainframe++;
	return (0);
}

void	start_game(char **argv)
{
	t_game	game;

	map_init(argv[1], &game);
	game.width = IMG_SIZE * game.map.cols;
	game.height = IMG_SIZE * game.map.rows;
	game.title = argv[0];
	game.animeframe = 0;
	game.mlx = mlx_init();
	game.window = mlx_new_window(game.mlx, game.width,
								 game.height + 16, game.title);
	hook_init(&game);
	mlx_loop_hook(game.mlx, *update_frames, &game);
	mlx_loop(game.mlx);
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
