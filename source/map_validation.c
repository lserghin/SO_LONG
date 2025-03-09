/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:54:13 by lserghin          #+#    #+#             */
/*   Updated: 2025/03/09 13:12:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_floodfill(t_game *game, int x, int y)
{
	if (x < 0 || y < 0 || !*(game->map + y) || !*(*(game->map + y) + x)
		|| *(*(game->map + y) + x) == WALL || *(*(game->map + y) + x) == 'V'
		|| *(*(game->map + y) + x + 1) == '\n')
		return ;
	*(*(game->map + y) + x) = 'V';
	ft_floodfill(game, x - 1, y);
	ft_floodfill(game, x + 1, y);
	ft_floodfill(game, x, y - 1);
	ft_floodfill(game, x, y + 1);
	return ;
}

int	ft_check_map_borders(t_game *game)
{
	int		lastcolumne;
	char	*firstline;
	char	*lastline;
	char	**var_map;

	firstline = *game->map;
	lastline = *(game->map + game->map_height - 1);
	lastcolumne = game->map_width - 1;
	var_map = game->map;
	while (*var_map && *var_map != lastline)
	{
		if (*(*var_map) != WALL || *((*var_map) + lastcolumne) != WALL)
			return (0);
		var_map++;
	}
	while (*firstline != '\n' && *lastline)
	{
		if (*firstline != WALL || *lastline != WALL)
			return (0);
		firstline++;
		lastline++;
	}
	return (1);
}

int	ft_check_map_components1(t_game *game)
{
	char	**map;
	char	*mapline;
	int		len_columns;

	map = game->map;
	while (*map)
	{
		mapline = *map;
		len_columns = 0;
		while (*mapline && *mapline != '\n')
		{
			if (*mapline == WALL || *mapline == EMPTY || *mapline == COLLECTABLE
				|| *mapline == EXIT || *mapline == PLAYER)
				len_columns++;
			mapline++;
		}
		if (len_columns != game->map_width)
			return (0);
		map++;
	}
	return (1);
}

int	ft_check_map_components2(t_game *game)
{
	char	**map;
	char	*mapline;

	map = game->map;
	while (*map)
	{
		mapline = *map;
		while (*mapline)
		{
			if (*mapline == PLAYER)
				game->p.count++;
			else if (*mapline == EXIT)
				game->e_count++;
			else if (*mapline == COLLECTABLE)
				game->c_count++;
			mapline++;
		}
		map++;
	}
	if (game->p.count != 1 || game->e_count != 1 || game->c_count < 1)
		return (0);
	return (1);
}

int	ft_check_map_path_valid(t_game *game)
{
	char	**map;
	char	*mapline;

	ft_floodfill(game, game->p.x, game->p.y);
	map = game->map;
	while (*map)
	{
		mapline = *map;
		while (*mapline)
		{
			if (*mapline == COLLECTABLE || *mapline == EXIT)
				return (0);
			mapline++;
		}
		map++;
	}
	return (1);
}
