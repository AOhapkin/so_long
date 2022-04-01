#include "so_long.h"

void	validate_map(t_game *game)
{
	validate_map_chars(game);
	validate_map_borders(game);
	map_verify_components(game);
}
