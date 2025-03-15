/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserghin <lserghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:22:11 by lserghin          #+#    #+#             */
/*   Updated: 2025/03/14 16:43:14 by lserghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_render_tile_utils(t_game *game, int x, int y)
{
	if (*(*(game->map + y) + x) == PLAYER)
	{
		if (game->is_moving)
			mlx_put_image_to_window(game->mlx, game->win,
				*(*(game->player_img + game->p.direction)
					+ game->current_p_frame),
				x * TILE_SIZE, y * TILE_SIZE);
		else
			mlx_put_image_to_window(game->mlx, game->win,
				*(*(game->player_img + game->p.direction) + 0),
				x * TILE_SIZE, y * TILE_SIZE);
	}
	else if (*(*(game->map + y) + x) == EXIT)
	{
		if (game->c_count == 0)
			mlx_put_image_to_window(game->mlx, game->win, game->exito_img,
				x * TILE_SIZE, y * TILE_SIZE);
		else
			mlx_put_image_to_window(game->mlx, game->win, game->exitc_img,
				x * TILE_SIZE, y * TILE_SIZE);
	}
	return ;
}

void	ft_render_tile(t_game *game, int x, int y)
{
	if (*(*(game->map + y) + x) == EMPTY)
		mlx_put_image_to_window(game->mlx, game->win, game->bg_img,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (*(*(game->map + y) + x) == WALL)
		mlx_put_image_to_window(game->mlx, game->win, game->wall_img,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (*(*(game->map + y) + x) == ENEMY)
		mlx_put_image_to_window(game->mlx, game->win, game->enemy_img,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (*(*(game->map + y) + x) == COLLECTABLE)
		mlx_put_image_to_window(game->mlx, game->win,
			*(game->collectable_img + game->current_c_frame),
			x * TILE_SIZE, y * TILE_SIZE);
	ft_render_tile_utils(game, x, y);
	return ;
}

void	ft_render_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_height / TILE_SIZE)
	{
		x = 0;
		while (x < game->map_width / TILE_SIZE)
		{
			ft_render_tile(game, x, y);
			x++;
		}
		y++;
	}
	return ;
}

int	ft_render_frame(t_game *game)
{
	static int	frame_count;

	if (frame_count <= ANIMATION_DELAY)
		return (frame_count++, 0);
	frame_count = 0;
	game->current_p_frame = (game->current_p_frame + 1) % 4;
	game->current_c_frame = (game->current_c_frame + 1) % 4;
	ft_enemy_move(game);
	ft_render_map(game);
	ft_record_player_steps(game);
	return (0);
}
