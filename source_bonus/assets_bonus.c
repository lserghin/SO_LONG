/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assets_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:21:08 by lserghin          #+#    #+#             */
/*   Updated: 2025/03/09 16:51:52 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_set_directions(char *directions[4][4])
{
	*(*(directions + 0) + 0) = "assets/p/p_u_1.xpm";
	*(*(directions + 0) + 1) = "assets/p/p_u_2.xpm";
	*(*(directions + 0) + 2) = "assets/p/p_u_3.xpm";
	*(*(directions + 0) + 3) = "assets/p/p_u_4.xpm";
	*(*(directions + 1) + 0) = "assets/p/p_d_1.xpm";
	*(*(directions + 1) + 1) = "assets/p/p_d_2.xpm";
	*(*(directions + 1) + 2) = "assets/p/p_d_3.xpm";
	*(*(directions + 1) + 3) = "assets/p/p_d_4.xpm";
	*(*(directions + 2) + 0) = "assets/p/p_l_1.xpm";
	*(*(directions + 2) + 1) = "assets/p/p_l_2.xpm";
	*(*(directions + 2) + 2) = "assets/p/p_l_3.xpm";
	*(*(directions + 2) + 3) = "assets/p/p_l_4.xpm";
	*(*(directions + 3) + 0) = "assets/p/p_r_1.xpm";
	*(*(directions + 3) + 1) = "assets/p/p_r_2.xpm";
	*(*(directions + 3) + 2) = "assets/p/p_r_3.xpm";
	*(*(directions + 3) + 3) = "assets/p/p_r_4.xpm";
	return ;
}

void	ft_load_asset_player(t_game *game)
{
	int		i;
	int		j;
	char	*directions[4][4];

	ft_set_directions(directions);
	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			*(*(game->player_img + i) + j) = mlx_xpm_file_to_image(game->mlx,
					*(*(directions + i) + j), &(int){TILE_SIZE},
					&(int){TILE_SIZE});
			if (!*(*(game->player_img + i) + j))
				ft_exitwitherror(game, "FAILED TO LOAD PLAYER TEXTURE!\n");
			j++;
		}
		i++;
	}
	return ;
}

void	ft_load_asset_collectables(t_game *game)
{
	*(game->collectable_img + 0) = mlx_xpm_file_to_image(game->mlx,
			"assets/c/c_1.xpm", &(int){TILE_SIZE}, &(int){TILE_SIZE});
	*(game->collectable_img + 1) = mlx_xpm_file_to_image(game->mlx,
			"assets/c/c_2.xpm", &(int){TILE_SIZE}, &(int){TILE_SIZE});
	*(game->collectable_img + 2) = mlx_xpm_file_to_image(game->mlx,
			"assets/c/c_3.xpm", &(int){TILE_SIZE}, &(int){TILE_SIZE});
	*(game->collectable_img + 3) = mlx_xpm_file_to_image(game->mlx,
			"assets/c/c_4.xpm", &(int){TILE_SIZE}, &(int){TILE_SIZE});
	if (!*(game->collectable_img + 0) || !*(game->collectable_img + 1)
		|| !*(game->collectable_img + 2) || !*(game->collectable_img + 3))
		ft_exitwitherror(game, "FAILED TO LOAD COLLECTIBLE TEXTURE!\n");
	return ;
}

void	ft_load_assets(t_game *game)
{
	game->bg_img = mlx_xpm_file_to_image(game->mlx, "assets/bg.xpm",
			&(int){TILE_SIZE}, &(int){TILE_SIZE});
	if (!game->bg_img)
		ft_exitwitherror(game, "FAILED TO LOAD BACKGROUND TEXTURE!\n");
	game->wall_img = mlx_xpm_file_to_image(game->mlx, "assets/w.xpm",
			&(int){TILE_SIZE}, &(int){TILE_SIZE});
	if (!game->wall_img)
		ft_exitwitherror(game, "FAILED TO LOAD WALL TEXTURE!\n");
	game->exito_img = mlx_xpm_file_to_image(game->mlx, "assets/e_o.xpm",
			&(int){TILE_SIZE}, &(int){TILE_SIZE});
	if (!game->exito_img)
		ft_exitwitherror(game, "FAILED TO LOAD EXIT TEXTURE!\n");
	game->exitc_img = mlx_xpm_file_to_image(game->mlx, "assets/e_c.xpm",
			&(int){TILE_SIZE}, &(int){TILE_SIZE});
	if (!game->exitc_img)
		ft_exitwitherror(game, "FAILED TO LOAD EXIT TEXTURE!\n");
	game->enemy_img = mlx_xpm_file_to_image(game->mlx, "assets/m/m_d.xpm",
			&(int){TILE_SIZE}, &(int){TILE_SIZE});
	if (!game->enemy_img)
		ft_exitwitherror(game, "FAILED TO LOAD ENEMY TEXTURE!\n");
	ft_load_asset_collectables(game);
	ft_load_asset_player(game);
	return ;
}
