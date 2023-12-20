/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:47:05 by junkim2           #+#    #+#             */
/*   Updated: 2023/11/23 13:49:06 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	key_up(t_mlx *mlx, t_imgpack imgpack)
{
	int	x;
	int	y;
	int	gx;
	int	gy;

	x = mlx->cat_loc.x;
	y = mlx->cat_loc.y;
	gx = x * imgpack.width;
	gy = y * imgpack.height;
	if (0 > y - 1 || mlx->map[y - 1][x] == '1')
		return ;
	if (mlx->map[y - 1][x] == 'C')
		eat_tuna(mlx, imgpack, x, y - 1);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
	imgpack.cat[0][mlx->log % 4], gx, (y - 1) * BLOCK_SIZE);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, imgpack.tile, gx, gy);
	mlx->cat_loc.y--;
	mlx->log++;
}

void	key_down(t_mlx *mlx, t_imgpack imgpack)
{
	int	x;
	int	y;
	int	gx;
	int	gy;

	x = mlx->cat_loc.x;
	y = mlx->cat_loc.y;
	gx = x * imgpack.width;
	gy = y * imgpack.height;
	if (mlx->height < y + 1 || mlx->map[y + 1][x] == '1')
		return ;
	if (mlx->map[y + 1][x] == 'C')
		eat_tuna(mlx, imgpack, x, y + 1);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
	imgpack.cat[1][mlx->log % 4], gx, (y + 1) * BLOCK_SIZE);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, imgpack.tile, gx, gy);
	mlx->cat_loc.y++;
	mlx->log++;
}

void	key_left(t_mlx *mlx, t_imgpack imgpack)
{
	int	x;
	int	y;
	int	gx;
	int	gy;

	x = mlx->cat_loc.x;
	y = mlx->cat_loc.y;
	gx = x * imgpack.width;
	gy = y * imgpack.height;
	if (0 > x - 1 || mlx->map[y][x - 1] == '1')
		return ;
	if (mlx->map[y][x - 1] == 'C')
		eat_tuna(mlx, imgpack, x - 1, y);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
	imgpack.cat[2][mlx->log % 4], (x - 1) * BLOCK_SIZE, gy);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, imgpack.tile, gx, gy);
	mlx->cat_loc.x--;
	mlx->log++;
}

void	key_right(t_mlx *mlx, t_imgpack imgpack)
{
	int	x;
	int	y;
	int	gx;
	int	gy;

	x = mlx->cat_loc.x;
	y = mlx->cat_loc.y;
	gx = x * imgpack.width;
	gy = y * imgpack.height;
	if (mlx->width < x + 1 || mlx->map[y][x + 1] == '1')
		return ;
	if (mlx->map[y][x + 1] == 'C')
		eat_tuna(mlx, imgpack, x + 1, y);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
	imgpack.cat[3][mlx->log % 4], (x + 1) * BLOCK_SIZE, gy);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, imgpack.tile, gx, gy);
	mlx->cat_loc.x++;
	mlx->log++;
}

int	key_event(int keycode, t_mlx *mlx)
{
	printf("%d\n", mlx->tuna_count);
	if (keycode == KEYCODE_UP)
		key_up(mlx, mlx->imgpack);
	else if (keycode == KEYCODE_DOWN)
		key_down(mlx, mlx->imgpack);
	else if (keycode == KEYCODE_LEFT)
		key_left(mlx, mlx->imgpack);
	else if (keycode == KEYCODE_RIGHT)
		key_right(mlx, mlx->imgpack);
	else if (keycode == KEYCODE_ESC)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
	mlx->imgpack.wall, 0, 0);
	mlx_string_put(mlx->mlx_ptr, mlx->win_ptr, 10, 10, RED, \
	ft_itoa(mlx->log));
	return (0);
}
