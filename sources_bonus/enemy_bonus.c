/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:38:28 by junkim2           #+#    #+#             */
/*   Updated: 2023/11/30 14:53:04 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	check_lose(t_mlx *mlx, int x, int y)
{
	if (x == mlx->enemy_loc.x && y == mlx->enemy_loc.y)
		exit_game(mlx, 0, "you lose");
}

static int	move_render(t_mlx *mlx, t_location now, int x, int y)
{
	int	gx;
	int	gy;

	gx = now.x * mlx->imgpack.width;
	gy = now.y * mlx->imgpack.height;
	if (now.x + x < 0 || now.x + x > mlx->width || \
		now.y + y < 0 || now.y + y > mlx->height \
		|| mlx->map[now.y + y][now.x + x] == '1')
		return (0);
	mlx->enemy_loc.x = now.x + x;
	mlx->enemy_loc.y = now.y + y;
	check_lose(mlx, mlx->cat_loc.x, mlx->cat_loc.y);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->imgpack.enemy, \
		(now.x + x) * mlx->imgpack.width, (now.y + y) * mlx->imgpack.height);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->imgpack.tile, \
		gx, gy);
	if (mlx->map[now.y][now.x] == 'C')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->imgpack.tuna, \
		gx + mlx->imgpack.width / 4, gy + mlx->imgpack.height / 4);
	if (mlx->map[now.y][now.x] == 'E')
		mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->imgpack.exit, \
		gx, gy);
	return (1);
}

int	move_enemy(t_mlx *mlx)
{
	t_location			now;
	int					distance_x;
	int					distance_y;
	static int			timer;

	timer++;
	if (timer % ENEMY_SPEED != 0)
		return (1);
	now = mlx->enemy_loc;
	distance_x = mlx->cat_loc.x - now.x;
	distance_y = mlx->cat_loc.y - now.y;
	if (distance_x != 0 && abs(distance_x) >= abs(distance_y))
	{
		if (!move_render(mlx, now, distance_x / abs(distance_x), 0) \
			&& distance_y != 0)
			move_render(mlx, now, 0, distance_y / abs(distance_y));
	}
	else
	{
		if (!move_render(mlx, now, 0, distance_y / abs(distance_y)) \
			&& distance_x != 0)
			move_render(mlx, now, distance_x / abs(distance_x), 0);
	}
	check_lose(mlx, mlx->cat_loc.x, mlx->cat_loc.y);
	return (1);
}
