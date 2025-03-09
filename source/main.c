/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:39:16 by lserghin          #+#    #+#             */
/*   Updated: 2025/03/09 17:07:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_exitwitherror(t_game *game, char *message)
{
	ft_printf("Error\n");
	if (message)
		ft_printf("%s", message);
	if (game && game->mlx)
		mlx_loop_end(game->mlx);
	ft_cleanup_game(game);
	exit(EXIT_FAILURE);
}

int	ft_close_window(t_game *game)
{
	ft_printf("WINDOW CLOSED!\nEXITING...\n");
	ft_cleanup_game(game);
	exit(EXIT_SUCCESS);
}

void	ft_setup_graphics(t_game *game)
{
	game->map_width *= TILE_SIZE;
	game->map_height *= TILE_SIZE;
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_exitwitherror(game, "FAILED TO INITIALIZE MINILIBX!\n");
	game->win = mlx_new_window(game->mlx, game->map_width,
			game->map_height, WINDOW_TITLE);
	if (!game->win)
		ft_exitwitherror(game, "FAILED TO CREATE WINDOW!\n");
	mlx_key_hook(game->win, ft_handle_input, game);
	mlx_hook(game->win, 17, 0, ft_close_window, game);
	ft_load_assets(game);
	ft_render_map(game);
	return ;
}

void	ft_map_validation(t_game *game)
{
	char	**map;

	game->map = ft_stash_map(game);
	if (!game->map)
		ft_exitwitherror(game, "FAILED TO LOAD MAP!\n");
	ft_get_player_coordinates(game);
	if (!ft_check_map_components1(game) || !ft_check_map_components2(game))
		ft_exitwitherror(game, "MAP COMPONENTS ARE INVALID!\n");
	if (!ft_check_map_borders(game))
		ft_exitwitherror(game, "MAP BORDERS ARE INVALID!\n");
	if (!ft_check_map_path_valid(game))
		ft_exitwitherror(game, "MAP PATHS ARE INVALID!\n");
	map = game->map;
	while (*map)
		free(*map++);
	free(game->map);
	return ;
}

int	main(int ac, char **av)
{
	t_game	*game;

	if (ac != 2)
		return (ft_printf("Error\nINVALID INPUTS!\n"), 1);
	game = (t_game *)malloc(sizeof(t_game) * 1);
	if (!game)
		ft_exitwitherror(game, "FAILED TO ALLOCATE MEMORY FOR GAME!\n");
	ft_memset(game, 0, sizeof(t_game));
	game->map_file = *(av + 1);
	if (!ft_strchr(game->map_file, '.')
		|| *(ft_strchr(game->map_file, '.') - 1) == '/'
		|| *(game->map_file) == '.'
		|| ft_strncmp(ft_strchr(game->map_file, '.'), ".ber\0", 5) != 0)
		ft_exitwitherror(game, "INVALID MAP NAME!\n");
	ft_map_validation(game);
	game->map = ft_stash_map(game);
	if (!game->map)
		ft_exitwitherror(game, "FAILED TO LOAD MAP!\n");
	ft_setup_graphics(game);
	mlx_loop(game->mlx);
	ft_cleanup_game(game);
	return (0);
}
