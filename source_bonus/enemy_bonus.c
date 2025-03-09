/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserghin <lserghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:21:21 by lserghin          #+#    #+#             */
/*   Updated: 2025/02/03 20:21:21 by lserghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_get_enemy_coordinates(t_game *game)
{
	game->e.y = 0;
	while (*(game->map + game->e.y))
	{
		game->e.x = 0;
		while (*(*(game->map + game->e.y) + game->e.x))
		{
			if (*(*(game->map + game->e.y) + game->e.x) == ENEMY)
			{
				if (game->e.direction < 0 || game->e.direction > 3)
					game->e.direction = rand() % 4;
				return ;
			}
			game->e.x++;
		}
		game->e.y++;
	}
	game->e.x = -1;
	game->e.y = -1;
	return ;
}

void	ft_update_enemy_image(t_game *game)
{
	mlx_destroy_image(game->mlx, game->enemy_img);
	if (game->e.direction == 0)
		game->enemy_img = mlx_xpm_file_to_image(game->mlx,
				"assets/m/m_u.xpm", &(int){TILE_SIZE}, &(int){TILE_SIZE});
	else if (game->e.direction == 1)
		game->enemy_img = mlx_xpm_file_to_image(game->mlx,
				"assets/m/m_d.xpm", &(int){TILE_SIZE}, &(int){TILE_SIZE});
	else if (game->e.direction == 2)
		game->enemy_img = mlx_xpm_file_to_image(game->mlx,
				"assets/m/m_l.xpm", &(int){TILE_SIZE}, &(int){TILE_SIZE});
	else if (game->e.direction == 3)
		game->enemy_img = mlx_xpm_file_to_image(game->mlx,
				"assets/m/m_r.xpm", &(int){TILE_SIZE}, &(int){TILE_SIZE});
	if (!game->enemy_img)
		ft_exitwitherror(game, "FAILED TO LOAD ENEMY TEXTURE!\n");
	return ;
}

void	ft_enemy_move_utils(t_game *game)
{
	static int	prev_tile = EMPTY;

	*(*(game->map + game->e.y) + game->e.x) = prev_tile;
	game->e.x = game->e.new_x;
	game->e.y = game->e.new_y;
	prev_tile = *(*(game->map + game->e.new_y) + game->e.new_x);
	*(*(game->map + game->e.new_y) + game->e.new_x) = ENEMY;
	ft_update_enemy_image(game);
	return ;
}

void	ft_update_enemy_direction(t_game *game)
{
	game->e.new_x = game->e.x;
	game->e.new_y = game->e.y;
	if (game->e.direction == 0)
		game->e.new_y--;
	else if (game->e.direction == 1)
		game->e.new_y++;
	else if (game->e.direction == 2)
		game->e.new_x--;
	else if (game->e.direction == 3)
		game->e.new_x++;
	return ;
}

void	ft_enemy_move(t_game *game)
{
	game->enemy_move_counter++;
	if (game->enemy_move_counter < SPEED_DELAY)
		return ;
	game->enemy_move_counter = 0;
	ft_get_enemy_coordinates(game);
	if (game->e.x == -1 && game->e.y == -1)
		return ;
	ft_update_enemy_direction(game);
	if (game->e.new_x >= 0 && game->e.new_x < game->map_width
		&& game->e.new_y >= 0 && game->e.new_y < game->map_height
		&& (*(*(game->map + game->e.new_y) + game->e.new_x) != WALL))
	{
		if (*(*(game->map + game->e.new_y) + game->e.new_x) == PLAYER)
		{
			ft_printf("YOU ARE DEAD☠️\nGAME OVER!.\n");
			return (mlx_loop_end(game->mlx), ft_cleanup_game(game), exit(0));
		}
		ft_enemy_move_utils(game);
	}
	else
		game->e.direction = rand() % 4;
	return ;
}
