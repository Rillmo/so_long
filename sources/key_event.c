/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:47:05 by junkim2           #+#    #+#             */
/*   Updated: 2023/11/24 20:09:08 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	key_up(t_mlx *mlx, t_imgpack imgpack)
{
	int		x;
	int		y;
	int		gx;
	int		gy;
	char	*log;

	x = mlx->cat_loc.x;
	y = mlx->cat_loc.y;
	gx = x * imgpack.width;
	gy = y * imgpack.height;
	if (0 > y - 1 || mlx->map[y - 1][x] == '1')
		return ;
	check_win(mlx, x, y - 1);
	if (mlx->map[y - 1][x] == 'C')
		eat_tuna(mlx, imgpack, x, y - 1);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
	imgpack.cat[3][0], gx, (y - 1) * BLOCK_SIZE);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, imgpack.tile, gx, gy);
	if (mlx->map[y][x] == 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
	imgpack.exit, gx, gy);
	mlx->cat_loc.y--;
	check_err(mlx, ft_itoa(mlx->log++), "(f)itoa error", &log);
	ft_putstr_fd(log, 1);
	write(1, "\n", 1);
}

void	key_down(t_mlx *mlx, t_imgpack imgpack)
{
	int		x;
	int		y;
	int		gx;
	int		gy;
	char	*log;

	x = mlx->cat_loc.x;
	y = mlx->cat_loc.y;
	gx = x * imgpack.width;
	gy = y * imgpack.height;
	if (mlx->height < y + 1 || mlx->map[y + 1][x] == '1')
		return ;
	check_win(mlx, x, y + 1);
	if (mlx->map[y + 1][x] == 'C')
		eat_tuna(mlx, imgpack, x, y + 1);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
	imgpack.cat[3][0], gx, (y + 1) * BLOCK_SIZE);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, imgpack.tile, gx, gy);
	if (mlx->map[y][x] == 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
		imgpack.exit, gx, gy);
	mlx->cat_loc.y++;
	check_err(mlx, ft_itoa(mlx->log++), "(f)itoa error", &log);
	ft_putstr_fd(log, 1);
	write(1, "\n", 1);
}

void	key_left(t_mlx *mlx, t_imgpack imgpack)
{
	int		x;
	int		y;
	int		gx;
	int		gy;
	char	*log;

	x = mlx->cat_loc.x;
	y = mlx->cat_loc.y;
	gx = x * imgpack.width;
	gy = y * imgpack.height;
	if (0 > x - 1 || mlx->map[y][x - 1] == '1')
		return ;
	check_win(mlx, x - 1, y);
	if (mlx->map[y][x - 1] == 'C')
		eat_tuna(mlx, imgpack, x - 1, y);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
	imgpack.cat[3][0], (x - 1) * BLOCK_SIZE, gy);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, imgpack.tile, gx, gy);
	if (mlx->map[y][x] == 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
		imgpack.exit, gx, gy);
	mlx->cat_loc.x--;
	check_err(mlx, ft_itoa(mlx->log++), "(f)itoa error", &log);
	ft_putstr_fd(log, 1);
	write(1, "\n", 1);
}

void	key_right(t_mlx *mlx, t_imgpack imgpack)
{
	int		x;
	int		y;
	int		gx;
	int		gy;
	char	*log;

	x = mlx->cat_loc.x;
	y = mlx->cat_loc.y;
	gx = x * imgpack.width;
	gy = y * imgpack.height;
	if (mlx->width < x + 1 || mlx->map[y][x + 1] == '1')
		return ;
	check_win(mlx, x + 1, y);
	if (mlx->map[y][x + 1] == 'C')
		eat_tuna(mlx, imgpack, x + 1, y);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
	imgpack.cat[3][0], (x + 1) * BLOCK_SIZE, gy);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, imgpack.tile, gx, gy);
	if (mlx->map[y][x] == 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, \
		imgpack.exit, gx, gy);
	mlx->cat_loc.x++;
	check_err(mlx, ft_itoa(mlx->log++), "(f)itoa error", &log);
	ft_putstr_fd(log, 1);
	write(1, "\n", 1);
}

int	key_event(int keycode, t_mlx *mlx)
{
	if (keycode == KEYCODE_UP)
		key_up(mlx, mlx->imgpack);
	else if (keycode == KEYCODE_DOWN)
		key_down(mlx, mlx->imgpack);
	else if (keycode == KEYCODE_LEFT)
		key_left(mlx, mlx->imgpack);
	else if (keycode == KEYCODE_RIGHT)
		key_right(mlx, mlx->imgpack);
	else if (keycode == KEYCODE_ESC)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		exit_game(mlx, 0, "exit");
	}
	return (0);
}
