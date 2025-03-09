/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 22:06:51 by lserghin          #+#    #+#             */
/*   Updated: 2025/03/07 17:18:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

# define TILE_SIZE 32
# define WINDOW_TITLE "So Long"

# define KEY_W 119
# define KEY_UP 65362
# define KEY_S 115
# define KEY_DOWN 65364 
# define KEY_A 97
# define KEY_LEFT 65361
# define KEY_D 100
# define KEY_RIGHT 65363
# define KEY_ESC 65307

# define WALL '1'
# define EMPTY '0'
# define PLAYER 'P'
# define COLLECTABLE 'C'
# define EXIT 'E'

typedef struct s_player
{
	int	steps;
	int	count;
	int	x;
	int	y;
}	t_player;

typedef struct s_game
{
	void		*collectable_img;
	void		*player_img;
	void		*exito_img;
	void		*exitc_img;
	void		*wall_img;
	void		*bg_img;
	void		*mlx;
	void		*win;
	int			map_width;
	int			map_height;
	int			c_count;
	int			e_count;
	int			exit_x;
	int			exit_y;
	int			moves;
	int			new_x;
	int			new_y;
	t_player	p;
	char		**map;
	char		*map_file;
}	t_game;

int		ft_handle_input(int keyinput, t_game *game);
int		ft_check_map_components1(t_game *game);
int		ft_check_map_components2(t_game *game);
int		ft_check_map_path_valid(t_game *game);
int		ft_check_map_borders(t_game *game);
int		ft_close_window(t_game *data);

void	ft_player_move(t_game *game, int x_player, int y_player);
void	ft_exitwitherror(t_game *game, char *message);
void	ft_floodfill(t_game *game, int x, int y);
void	ft_get_player_coordinates(t_game *game);
void	ft_cleanup_game(t_game *game);
void	ft_load_assets(t_game *game);
void	ft_render_map(t_game *game);

char	**ft_stash_map(t_game *game);

#endif
