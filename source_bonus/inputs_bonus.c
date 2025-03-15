/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserghin <lserghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:21:32 by lserghin          #+#    #+#             */
/*   Updated: 2025/03/14 16:40:14 by lserghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_key_input(int keyinput, t_game *game)
{
	if (keyinput == KEY_W || keyinput == KEY_UP)
	{
		game->p.direction = 0;
		game->is_moving = 1;
		ft_player_move(game, 0, -1);
	}
	if (keyinput == KEY_S || keyinput == KEY_DOWN)
	{
		game->p.direction = 1;
		game->is_moving = 1;
		ft_player_move(game, 0, 1);
	}
	if (keyinput == KEY_A || keyinput == KEY_LEFT)
	{
		game->p.direction = 2;
		game->is_moving = 1;
		ft_player_move(game, -1, 0);
	}
	if (keyinput == KEY_D || keyinput == KEY_RIGHT)
	{
		game->p.direction = 3;
		game->is_moving = 1;
		ft_player_move(game, 1, 0);
	}
	return ;
}

int	ft_handle_input(int keyinput, t_game *game)
{
	if (keyinput == KEY_ESC)
	{
		ft_printf("EXITING GAME...\nBYE BYE!.\n");
		mlx_loop_end(game->mlx);
		ft_cleanup_game(game);
		exit(0);
	}
	ft_key_input(keyinput, game);
	return (0);
}
