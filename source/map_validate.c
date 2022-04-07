#include "so_long.h"

void	choose_player_position(t_info *info)
{
	int	i;
	int	j;
	int	players;

	i = 0;
	players = 0;
	while (i < info->height)
	{
		j = 0;
		while (j < info-> width)
		{
			if (info->map[i][j] == 'P' && players > 0)
				info->map[i][j] = '0';
			if (info->map[i][j] == 'P' && players == 0)
				players++;
			j++;
		}
		i++;
	}
}

void	ft_map_error(t_game *game, int unknown)
{
	if (game->exit < 1 && game->players < 1 && game->coins < 1 \
			&& game->exit < 1)
		ft_error_exit("Map error: no elements", game);
	if (game->exit < 1)
		ft_error_exit("Map error: there is no exit", game);
	if (game->players < 1)
		ft_error_exit("Map error: there is no player position", game);
	if (game->players > 1)
		choose_player_position(game);
	if (game->coins < 1)
		ft_error_exit("Map error: there are no collectibles", game);
	if (unknown > 0)
		ft_error_exit("Map error: there are unknown characters", game);
}

void	check_chars(t_game *game)
{
	int	unknown;
	int	i;
	int	j;

	i = 0;
	unknown = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game-> width)
		{
			if (game->map[i][j] == 'E')
				game->exit++;
			else if (game->map[i][j] == 'P')
				game->players++;
			else if (game->map[i][j] == 'C')
				game->coins++;
			else if (game->map[i][j] != '1' && game->map[i][j] != '0')
				unknown++;
			j++;
		}
		i++;
	}
	ft_map_error(game, unknown);
}

void	ft_is_wall(t_game *game, int i)
{
	int	j;

	j = 0;
	while (game->map[i][j])
	{
		if (game->map[i][j] != '1')
			ft_error_exit("The map is not surrounded by walls!\n", game);
		j++;
	}
}

void	check_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		if (i == 0 || i == game->height - 1)
			ft_is_wall(game, i);
		else if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
			ft_error_exit("The map is not surrounded by walls!\n", game);
		i++;
	}
}