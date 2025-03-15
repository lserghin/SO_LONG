/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lserghin <lserghin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 23:16:29 by lserghin          #+#    #+#             */
/*   Updated: 2025/03/15 01:50:37 by lserghin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_load_assets(t_game *game)
{
	game->bg_img = mlx_xpm_file_to_image(game->mlx, "textures/bg.xpm",
			&(int){TILE_SIZE}, &(int){TILE_SIZE});
	if (!game->bg_img)
		ft_exitwitherror(game, "FAILED TO LOAD BACKGROUND TEXTURE!\n");
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "textures/w.xpm",
			&(int){TILE_SIZE}, &(int){TILE_SIZE});
	if (!game->wall_img)
		ft_exitwitherror(game, "FAILED TO LOAD WALL TEXTURE!\n");
	game->collectable_img = mlx_xpm_file_to_image(game->mlx, "textures/c.xpm",
			&(int){TILE_SIZE}, &(int){TILE_SIZE});
	if (!game->collectable_img)
		ft_exitwitherror(game, "FAILED TO LOAD COLLECTABLE TEXTURE!\n");
	game->exito_img = mlx_xpm_file_to_image(game->mlx, "textures/e_o.xpm",
			&(int){TILE_SIZE}, &(int){TILE_SIZE});
	if (!game->exito_img)
		ft_exitwitherror(game, "FAILED TO LOAD EXIT TEXTURE!\n");
	game->exitc_img = mlx_xpm_file_to_image(game->mlx, "textures/e_c.xpm",
			&(int){TILE_SIZE}, &(int){TILE_SIZE});
	if (!game->exitc_img)
		ft_exitwitherror(game, "FAILED TO LOAD EXIT TEXTURE!\n");
	game->player_img = mlx_xpm_file_to_image(game->mlx, "textures/p.xpm",
			&(int){TILE_SIZE}, &(int){TILE_SIZE});
	if (!game->player_img)
		ft_exitwitherror(game, "FAILED TO LOAD PLAYER TEXTURE!\n");
	return ;
}
