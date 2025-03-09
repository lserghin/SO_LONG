/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:22:06 by lserghin          #+#    #+#             */
/*   Updated: 2025/03/07 16:03:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_record_player_steps(t_game *game)
{
	char	*steps;
	char	*string;

	steps = ft_itoa(game->p.steps);
	string = ft_strjoin("Steps : ", steps);
	mlx_string_put(game->mlx, game->win, 5, 10, 0xFFFF00, string);
	free(string);
	free(steps);
	return ;
}

void	ft_get_player_coordinates(t_game *game)
{
	game->p.y = 0;
	while (*(game->map + game->p.y))
	{
		game->p.x = 0;
		while (*(*(game->map + game->p.y) + game->p.x))
		{
			if (*(*(game->map + game->p.y) + game->p.x) == 'P')
				return ;
			game->p.x++;
		}
		game->p.y++;
	}
	game->p.x = -1;
	game->p.y = -1;
	return ;
}

void	ft_player_move_utils(t_game *game)
{
	if (*(*(game->map + game->exit_y) + game->exit_x) == PLAYER)
		*(*(game->map + game->p.y) + game->p.x) = EXIT;
	else
		*(*(game->map + game->p.y) + game->p.x) = EMPTY;
	game->p.x = game->p.new_x;
	game->p.y = game->p.new_y;
	*(*(game->map + game->p.new_y) + game->p.new_x) = PLAYER;
	game->p.steps++;
	ft_render_frame(game);
	return ;
}

void	ft_player_move(t_game *game, int x_player, int y_player)
{
	game->p.new_x = game->p.x + x_player;
	game->p.new_y = game->p.y + y_player;
	if (*(*(game->map + game->p.new_y) + game->p.new_x) == ENEMY)
	{
		ft_printf("YOU ARE DEAD!☠️\nGAME OVER!.\n");
		return (mlx_loop_end(game->mlx), ft_cleanup_game(game), exit(0));
	}
	if (*(*(game->map + game->p.new_y) + game->p.new_x) == WALL)
		return ;
	if (*(*(game->map + game->p.new_y) + game->p.new_x) == COLLECTABLE)
		game->c_count--;
	if (*(*(game->map + game->p.new_y) + game->p.new_x) == EXIT)
	{
		if (game->c_count == 0)
		{
			ft_printf("🎉CONGRATULATIONS!🎉\n🔥YOU WON THE GAME!🔥\n");
			return (mlx_loop_end(game->mlx), ft_cleanup_game(game), exit(0));
		}
		game->exit_x = game->p.new_x;
		game->exit_y = game->p.new_y;
	}
	ft_player_move_utils(game);
	return ;
}
