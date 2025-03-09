/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 00:22:52 by lserghin          #+#    #+#             */
/*   Updated: 2025/03/07 17:39:47 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_get_player_coordinates(t_game *game)
{
	game->p.y = 0;
	while (*(game->map + game->p.y))
	{
		game->p.x = 0;
		while (*(*(game->map + game->p.y) + game->p.x))
		{
			if (*(*(game->map + game->p.y) + game->p.x) == PLAYER)
				return ;
			game->p.x++;
		}
		game->p.y++;
	}
	game->p.x = -1;
	game->p.y = -1;
	return ;
}

void	ft_player_move(t_game *game, int x_player, int y_player)
{
	game->new_x = game->p.x + x_player;
	game->new_y = game->p.y + y_player;
	if (*(*(game->map + game->new_y) + game->new_x) == WALL)
		return ;
	if (*(*(game->map + game->new_y) + game->new_x) == COLLECTABLE)
		game->c_count--;
	if (*(*(game->map + game->new_y) + game->new_x) == EXIT)
	{
		if (game->c_count == 0)
		{
			ft_printf("🎉CONGRATULATIONS!🎉\n🔥YOU WON THE GAME!🔥\n");
			return (mlx_loop_end(game->mlx), ft_cleanup_game(game), exit(0));
		}
		game->exit_x = game->new_x;
		game->exit_y = game->new_y;
	}
	if (*(*(game->map + game->exit_y) + game->exit_x) == PLAYER)
		*(*(game->map + game->p.y) + game->p.x) = EXIT;
	else
		*(*(game->map + game->p.y) + game->p.x) = EMPTY;
	game->p.x = game->new_x;
	game->p.y = game->new_y;
	*(*(game->map + game->new_y) + game->new_x) = PLAYER;
	++game->p.steps;
	return (ft_printf("Steps :(%d)\n", game->p.steps), ft_render_map(game));
}
