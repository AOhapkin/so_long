#include "so_long.h"

void	ft_game_error(char *error_mesaage, t_game game)
{
	ft_putendl_fd("Error", 1);
	ft_putendl_fd(error_mesaage, 1);
}

void	start_game(char **argv)
{
	t_game	game;

	init_map(argv[1], &game);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl_fd("Bad arguments", 1);
		exit(EXIT_FAILURE);
	}
	start_game(argv);
	return (0);
}