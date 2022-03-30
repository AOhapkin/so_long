#include "so_long.h"

void	ft_show_error(char *error_mesaage)
{
	ft_putendl_fd("Error", 1);
	ft_putendl_fd(error_mesaage, 1);
}

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_show_error("Bad arguments");
		exit(EXIT_FAILURE);
	}

}