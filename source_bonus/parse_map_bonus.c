/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:21:54 by lserghin          #+#    #+#             */
/*   Updated: 2025/03/09 13:13:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_count_map_columns(char *mapline)
{
	int	len_columns;

	len_columns = 0;
	while (*mapline && *mapline != '\n')
	{
		len_columns++;
		mapline++;
	}
	return (len_columns);
}

int	ft_count_map_lines(t_game *game)
{
	int		len_lines;
	char	*mapline;
	int		fd;

	len_lines = 0;
	fd = open(game->map_file, O_RDONLY);
	if (fd < 0)
		return (0);
	mapline = get_next_line(fd);
	while (mapline)
	{
		free(mapline);
		mapline = get_next_line(fd);
		len_lines++;
	}
	return (close(fd), len_lines);
}

void	ft_freemap(t_game *game, char **map_pos)
{
	char	**var_map;

	if (!game || !map_pos)
		return ;
	var_map = game->map;
	while (var_map <= map_pos && *var_map)
		free(*var_map++);
	return (free(game->map));
}

char	**ft_stash_map(t_game *game)
{
	char	**var_map;
	int		fd;

	game->map_height = ft_count_map_lines(game);
	fd = open(game->map_file, O_RDONLY);
	game->map = malloc(sizeof(char *) * (game->map_height + 1));
	if (fd < 0 || !game->map || game->map_height == 0)
		return (close(fd), free(game->map), NULL);
	*game->map = get_next_line(fd);
	if (!*game->map)
		return (close(fd), free(game->map), NULL);
	var_map = game->map;
	game->map_width = ft_count_map_columns(*var_map);
	while (*var_map)
	{
		*++var_map = get_next_line(fd);
		if (!*var_map)
			break ;
		if (game->map_width != ft_count_map_columns(*var_map))
			return (close(fd), ft_freemap(game, var_map), NULL);
	}
	return (close(fd), game->map);
}
