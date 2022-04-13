/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmyriah <gmyriah@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:05:37 by gmyriah           #+#    #+#             */
/*   Updated: 2022/04/13 13:05:39 by gmyriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	choose_player_position(t_game *game)
{
	int	i;
	int	j;
	int	players;

	i = 0;
	players = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game-> width)
		{
			if (game->map[i][j] == 'P' && players > 0)
				game->map[i][j] = '0';
			if (game->map[i][j] == 'P' && players == 0)
				players++;
			j++;
		}
		i++;
	}
}

void	ft_map_error(t_game *game, int unknown)
{
	if (game->exit < 1)
		ft_game_error("There is no exit on the map", game);
	if (game->players < 1)
		ft_game_error("There is no player on the map", game);
	if (game->players > 1)
		ft_game_error("There are too many players on the map", game);
	if (game->coins < 1)
		ft_game_error("There are no collectibles on the map", game);
	if (unknown > 0)
		ft_game_error("There are invalid chars on the map", game);
}

void	validate_chars(t_game *game)
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

void	ft_is_wall(t_game *game, int line_number)
{
	int	j;

	j = 0;
	while (game->map[line_number][j])
	{
		if (game->map[line_number][j] != '1')
			ft_game_error("There must be walls on the edge of map", game);
		j++;
	}
}

void	validate_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height)
	{
		if (i == 0 || i == game->height - 1)
			ft_is_wall(game, i);
		else if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
			ft_game_error("There must be walls on the edge of map", game);
		i++;
	}
}
