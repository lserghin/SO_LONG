/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserghin <lserghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:24:28 by lserghin          #+#    #+#             */
/*   Updated: 2025/03/14 16:35:46 by lserghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_cleanup_images(t_game *game)
{
	if (game->bg_img)
		mlx_destroy_image(game->mlx, game->bg_img);
	if (game->exitc_img)
		mlx_destroy_image(game->mlx, game->exitc_img);
	if (game->exito_img)
		mlx_destroy_image(game->mlx, game->exito_img);
	if (game->player_img)
		mlx_destroy_image(game->mlx, game->player_img);
	if (game->collectable_img)
		mlx_destroy_image(game->mlx, game->collectable_img);
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	return ;
}

void	ft_cleanup_game(t_game *game)
{
	char	**map;

	if (!game)
		return ;
	if (game->map)
	{
		map = game->map;
		while (*map)
			free(*map++);
		free(game->map);
	}
	if (game->mlx)
	{
		ft_cleanup_images(game);
		if (game->win)
		{
			mlx_clear_window(game->mlx, game->win);
			mlx_destroy_window(game->mlx, game->win);
		}
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
	return ;
}
