/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmyriah <gmyriah@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 13:05:20 by gmyriah           #+#    #+#             */
/*   Updated: 2022/04/13 13:05:23 by gmyriah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "stdio.h"

void	init_game(t_game *game)
{
	game->mlx = mlx_init();
	game->coins = 0;
	game->x = 0;
	game->y = 0;
	game->moves_counter = 0;
	game->players = 0;
	game->exit = 0;
}

void ft_print_moves_counter(int counter)
{
	ft_putstr_fd("Movements: ", 1);
	ft_putnbr_fd((counter + 1), 1);
	ft_putendl_fd("", 1);
}

void	win_game(t_game *info)
{
	ft_putendl_fd("You've done it!", 1);
	ft_putstr_fd("Total moves: ", 1);
	ft_putnbr_fd((info->moves_counter + 1), 1);
	ft_putendl_fd(".", 1);
	ft_free_exit(info);
}

void	ft_move(t_game *game, int y, int x)
{
	char	destination;

	destination = game->map[y][x];
	if (destination == 'E' && game->coins == 0)
		win_game(game);
	if (destination == '1' || (destination == 'E' && game->coins > 0))
		return ;
	else if (destination == '0')
	{
		put_xpm_image(game->x * SCALE, game->y * SCALE, FLOOR_IMG, game);
		put_xpm_image(x * SCALE, y * SCALE, PLAYER_IMG, game);
	}
	else if (destination == 'C')
	{
		put_xpm_image(game->x * SCALE, game->y * SCALE, FLOOR_IMG, game);
		put_xpm_image(x * SCALE, y * SCALE, PLAYER_IMG, game);
		game->map[y][x] = '0';
		game->coins--;
	}
	game->y = y;
	game->x = x;
	ft_print_moves_counter(game->moves_counter++);
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == KEY_RIGHT || keycode == KEY_D)
		ft_move(game, game->y, game->x + 1);
	else if (keycode == KEY_LEFT || keycode == KEY_A)
		ft_move(game, game->y, game->x - 1);
	else if (keycode == KEY_UP || keycode == KEY_W)
		ft_move(game, game->y - 1, game->x);
	else if (keycode == KEY_DOWN || keycode == KEY_S)
		ft_move(game, game->y + 1, game->x);
	else if (keycode == KEY_ESC)
		ft_free_exit(game);
	return (0);
}
