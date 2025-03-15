/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserghin <lserghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 23:16:36 by lserghin          #+#    #+#             */
/*   Updated: 2025/03/14 16:36:17 by lserghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_handle_input(int keyinput, t_game *game)
{
	if (keyinput == KEY_ESC)
	{
		ft_printf("EXITING GAME...\nBYE BYE!\n");
		mlx_loop_end(game->mlx);
		ft_cleanup_game(game);
		exit(EXIT_SUCCESS);
	}
	if (keyinput == KEY_W || keyinput == KEY_UP)
		ft_player_move(game, 0, -1);
	else if (keyinput == KEY_S || keyinput == KEY_DOWN)
		ft_player_move(game, 0, 1);
	else if (keyinput == KEY_A || keyinput == KEY_LEFT)
		ft_player_move(game, -1, 0);
	else if (keyinput == KEY_D || keyinput == KEY_RIGHT)
		ft_player_move(game, 1, 0);
	return (0);
}
