/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:21:15 by lserghin          #+#    #+#             */
/*   Updated: 2025/03/06 16:20:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_cleanup_images_utils(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		if (*(game->collectable_img + i))
			mlx_destroy_image(game->mlx, (*(game->collectable_img + i)));
		i++;
	}
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (*(*(game->player_img + i) + j))
				mlx_destroy_image(game->mlx, *(*(game->player_img + i) + j));
			j++;
		}
		i++;
	}
	return ;
}

void	ft_cleanup_images(t_game *game)
{
	if (game->bg_img)
		mlx_destroy_image(game->mlx, game->bg_img);
	if (game->wall_img)
		mlx_destroy_image(game->mlx, game->wall_img);
	if (game->exito_img)
		mlx_destroy_image(game->mlx, game->exito_img);
	if (game->exitc_img)
		mlx_destroy_image(game->mlx, game->exitc_img);
	if (game->enemy_img)
		mlx_destroy_image(game->mlx, game->enemy_img);
	ft_cleanup_images_utils(game);
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
