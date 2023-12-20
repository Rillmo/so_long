/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:17:40 by junkim2           #+#    #+#             */
/*   Updated: 2023/11/23 12:17:06 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_sprite_image(t_mlx *mlx)
{
	int			i;
	int			j;
	char		tmp[30];
	const char	*filenames[4][4] = {
	{"images/up1.xpm", "images/up2.xpm", \
	"images/up3.xpm", "images/up4.xpm"},
	{"images/down1.xpm", "images/down2.xpm", \
	"images/down3.xpm", "images/down4.xpm"},
	{"images/left1.xpm", "images/left2.xpm", \
	"images/left3.xpm", "images/left4.xpm"},
	{"images/right1.xpm", "images/right2.xpm", \
	"images/right3.xpm", "images/right4.xpm"}
	};

	i = -1;
	while (++i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_strlcpy(tmp, filenames[i][j], 30);
			mlx->imgpack.cat[i][j++] = mlx_xpm_file_to_image(mlx->mlx_ptr, \
			tmp, &mlx->imgpack.width, &mlx->imgpack.height);
		}
	}
}

void	set_image(t_mlx *mlx)
{
	mlx->imgpack.width = BLOCK_SIZE;
	mlx->imgpack.height = BLOCK_SIZE;
	mlx->imgpack.tile = mlx_xpm_file_to_image(mlx->mlx_ptr, "images/tile.xpm", \
		&mlx->imgpack.width, &mlx->imgpack.height);
	mlx->imgpack.wall = mlx_xpm_file_to_image(mlx->mlx_ptr, "images/wall.xpm", \
		&mlx->imgpack.width, &mlx->imgpack.height);
	mlx->imgpack.tuna = mlx_xpm_file_to_image(mlx->mlx_ptr, \
		"images/tuna_30.xpm", &mlx->imgpack.width, &mlx->imgpack.height);
	mlx->imgpack.exit = mlx_xpm_file_to_image(mlx->mlx_ptr, "images/exit.xpm", \
		&mlx->imgpack.width, &mlx->imgpack.height);
	set_sprite_image(mlx);
}
