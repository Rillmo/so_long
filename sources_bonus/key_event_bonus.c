/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:47:05 by junkim2           #+#    #+#             */
/*   Updated: 2023/11/30 14:49:46 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

static void	move_cat(t_mlx *mlx, t_imgpack imgpack, int dir, t_location next)
{
	t_location	now;

	now = mlx->cat_loc;
	if (next.y > mlx->height || next.y < 0 || next.x > mlx->width || next.x < 0 \
		|| mlx->map[next.y][next.x] == '1')
		return ;
	if (mlx->map[next.y][next.x] == 'C')
		eat_tuna(mlx, imgpack, next.x, next.y);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
	imgpack.cat[dir][mlx->log % 4], next.x * imgpack.width, \
	next.y * imgpack.height);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->imgpack.tile, \
	now.x * imgpack.width, now.y * imgpack.height);
	if (mlx->map[now.y][now.x] == 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->imgpack.exit, \
		now.x * imgpack.height, now.y * imgpack.width);
	mlx->cat_loc = next;
	check_lose(mlx, next.x, next.y);
	check_win(mlx, next.x, next.y);
	mlx->log++;
}

// static void	key_down(t_mlx *mlx, t_imgpack imgpack)
// {
// 	int	x;
// 	int	y;
// 	int	gx;
// 	int	gy;

// 	x = mlx->cat_loc.x;
// 	y = mlx->cat_loc.y;
// 	gx = x * imgpack.width;
// 	gy = y * imgpack.height;
// 	if (mlx->height < y + 1 || mlx->map[y + 1][x] == '1')
// 		return ;
// 	check_lose(mlx, x, y + 1);
// 	check_win(mlx, x, y + 1);
// 	if (mlx->map[y + 1][x] == 'C')
// 		eat_tuna(mlx, imgpack, x, y + 1);
// 	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
// 	imgpack.cat[1][mlx->log % 4], gx, (y + 1) * BLOCK_SIZE);
// 	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, imgpack.tile, gx, gy);
// 	if (mlx->map[y][x] == 'E')
// 		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
// 		imgpack.exit, gx, gy);
// 	mlx->cat_loc.y++;
// 	mlx->log++;
// 	move_enemy(mlx);
// }

// static void	key_left(t_mlx *mlx, t_imgpack imgpack)
// {
// 	int	x;
// 	int	y;
// 	int	gx;
// 	int	gy;

// 	x = mlx->cat_loc.x;
// 	y = mlx->cat_loc.y;
// 	gx = x * imgpack.width;
// 	gy = y * imgpack.height;
// 	if (0 > x - 1 || mlx->map[y][x - 1] == '1')
// 		return ;
// 	check_lose(mlx, x - 1, y);
// 	check_win(mlx, x - 1, y);
// 	if (mlx->map[y][x - 1] == 'C')
// 		eat_tuna(mlx, imgpack, x - 1, y);
// 	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
// 	imgpack.cat[2][mlx->log % 4], (x - 1) * BLOCK_SIZE, gy);
// 	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, imgpack.tile, gx, gy);
// 	if (mlx->map[y][x] == 'E')
// 		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
// 		imgpack.exit, gx, gy);
// 	mlx->cat_loc.x--;
// 	mlx->log++;
// 	move_enemy(mlx);
// }

// static void	key_right(t_mlx *mlx, t_imgpack imgpack)
// {
// 	int	x;
// 	int	y;
// 	int	gx;
// 	int	gy;

// 	x = mlx->cat_loc.x;
// 	y = mlx->cat_loc.y;
// 	gx = x * imgpack.width;
// 	gy = y * imgpack.height;
// 	if (mlx->width < x + 1 || mlx->map[y][x + 1] == '1')
// 		return ;
// 	check_lose(mlx, x + 1, y);
// 	check_win(mlx, x + 1, y);
// 	if (mlx->map[y][x + 1] == 'C')
// 		eat_tuna(mlx, imgpack, x + 1, y);
// 	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
// 	imgpack.cat[3][mlx->log % 4], (x + 1) * BLOCK_SIZE, gy);
// 	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, imgpack.tile, gx, gy);
// 	if (mlx->map[y][x] == 'E')
// 		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
// 		imgpack.exit, gx, gy);
// 	mlx->cat_loc.x++;
// 	mlx->log++;
// 	move_enemy(mlx);
// }

void	map_keycode(t_mlx *mlx, int keycode)
{
	t_location	next;

	next.x = mlx->cat_loc.x;
	next.y = mlx->cat_loc.y;
	if (keycode == KEYCODE_UP)
	{
		next.y--;
		move_cat(mlx, mlx->imgpack, 0, next);
	}
	if (keycode == KEYCODE_DOWN)
	{
		next.y++;
		move_cat(mlx, mlx->imgpack, 1, next);
	}
	if (keycode == KEYCODE_LEFT)
	{
		next.x--;
		move_cat(mlx, mlx->imgpack, 2, next);
	}
	if (keycode == KEYCODE_RIGHT)
	{
		next.x++;
		move_cat(mlx, mlx->imgpack, 3, next);
	}
}

int	key_event(int keycode, t_mlx *mlx)
{
	char		*log;

	map_keycode(mlx, keycode);
	if (keycode == KEYCODE_ESC)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		exit_game(mlx, 0, "exit");
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
		mlx->imgpack.wall, 0, 0);
	check_err(mlx, ft_itoa(mlx->log), "(f)itoa error", &log);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 10, RED, log);
	return (0);
}
