/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:43:56 by junkim2           #+#    #+#             */
/*   Updated: 2023/11/30 15:06:19 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../mlx/mlx.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <math.h>

# define _ERROR 0
# define BUFF_SIZE 1000
# define BLOCK_SIZE 50
# define KEY_PRESS 2
# define KEYCODE_UP 126
# define KEYCODE_DOWN 125
# define KEYCODE_LEFT 123
# define KEYCODE_RIGHT 124
# define KEYCODE_ESC 53
# define RED 0x00FF0000
# define ENEMY_SPEED 5000

typedef struct s_location
{
	int	x;
	int	y;
}	t_location;

typedef struct s_imgpack
{
	int		width;
	int		height;
	void	*tile;
	void	*wall;
	void	*tuna;
	void	*exit;
	void	*cat[4][4];
	void	*enemy;
}	t_imgpack;

typedef struct s_mlx
{
	t_list		*heap;
	void		*mlx_ptr;
	void		*win_ptr;
	int			width;
	int			height;
	t_imgpack	imgpack;
	t_location	cat_loc;
	t_location	enemy_loc;
	char		**map;
	int			log;
	int			tuna_count;
}	t_mlx;

void		exit_game(t_mlx *mlx, int is_err, char *message);
void		check_err(t_mlx *mlx, void *content, \
			char *err_message, char **tosave);
void		reset_mlx(t_mlx *mlx);
void		set_image(t_mlx *mlx);
void		render_map(t_mlx *mlx);
int			key_event(int keycode, t_mlx *mlx);
void		read_map(t_mlx *mlx, int fd);
void		eat_tuna(t_mlx *mlx, t_imgpack imgpack, int x, int y);
char		**copy_map(char **map, int height);
t_location	get_cat_loc(char **map);
int			count_c(char **map);
int			mouse_event(t_mlx *mlx);
void		check_win(t_mlx *mlx, int x, int y);
int			move_enemy(t_mlx *mlx);
void		check_lose(t_mlx *mlx, int x, int y);

#endif
