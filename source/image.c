/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmyriah <gmyriah@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:05:30 by gmyriah           #+#    #+#             */
/*   Updated: 2022/04/13 13:05:32 by gmyriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_xpm_image(int x, int y, const char *file, t_game *game)
{
	int	w;
	int	h;

	game->img = mlx_xpm_file_to_image(game->mlx, (char *)file, &w, &h);
	mlx_put_image_to_window(game->mlx, game->win, game->img, x, y);
}

void	put_ground(int x, int y, char c, t_game *game)
{
	if (c == '1')
	{
		put_xpm_image(x, y, FLOOR_IMG, game);
		put_xpm_image(x, y, WALL_IMG, game);
	}
	else if (c == '0')
	{
		put_xpm_image(x, y, FLOOR_IMG, game);
	}
}

void	put_image(int x, int y, char c, t_game *game)
{
	put_ground(x, y, c, game);
	if (c == 'C')
	{
		put_xpm_image(x, y, FLOOR_IMG, game);
		put_xpm_image(x, y, COIN_IMG, game);
	}
	else if (c == 'P')
	{
		game->x = x / SCALE;
		game->y = y / SCALE;
		put_xpm_image(x, y, FLOOR_IMG, game);
		put_xpm_image(x, y, PLAYER_IMG, game);
		game->map[game->y][game->x] = '0';
	}
	else if (c == 'E')
	{
		put_xpm_image(x, y, FLOOR_IMG, game);
		put_xpm_image(x, y, EXIT_IMG, game);
	}
}

void	ft_put_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			put_image(j * SCALE, i * SCALE, game->map[i][j], game);
			++j;
		}
		++i;
	}
}
