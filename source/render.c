/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserghin <lserghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 22:31:11 by lserghin          #+#    #+#             */
/*   Updated: 2025/03/14 16:38:07 by lserghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_tile(t_game *game, int x, int y)
{
	if (*(*(game->map + y) + x) == EMPTY)
		mlx_put_image_to_window(game->mlx, game->win, game->bg_img,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (*(*(game->map + y) + x) == WALL)
		mlx_put_image_to_window(game->mlx, game->win, game->wall_img,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (*(*(game->map + y) + x) == PLAYER)
		mlx_put_image_to_window(game->mlx, game->win, game->player_img,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (*(*(game->map + y) + x) == COLLECTABLE)
		mlx_put_image_to_window(game->mlx, game->win, game->collectable_img,
			x * TILE_SIZE, y * TILE_SIZE);
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
