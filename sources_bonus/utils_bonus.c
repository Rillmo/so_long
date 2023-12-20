/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:46:42 by junkim2           #+#    #+#             */
/*   Updated: 2023/11/24 20:59:47 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	check_win(t_mlx *mlx, int x, int y)
{
	if (mlx->tuna_count == 0 && mlx->map[y][x] == 'E')
		exit_game(mlx, 0, "you win");
}

t_location	get_cat_loc(char **map)
{
	int			i;
	int			j;
	t_location	loc;

	loc.x = 0;
	loc.y = 0;
	i = 0;
	while (map[i] != 0)
	{
		j = 0;
		while (map[i][j] != 0)
		{
			if (map[i][j] == 'P')
			{
				loc.x = j;
				loc.y = i;
				return (loc);
			}
			j++;
		}
		i++;
	}
	return (loc);
}

char	**copy_map(char **map, int height)
{
	int		i;
	char	**cpy;

	cpy = (char **)ft_calloc(height + 1, sizeof(char *));
	if (cpy == NULL)
		return (NULL);
	i = 0;
	while (i < height)
	{
		cpy[i] = ft_strdup(map[i]);
		if (cpy == NULL)
			return (NULL);
		i++;
	}
	return (cpy);
}

int	count_c(char **map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map[i] != 0)
	{
		j = 0;
		while (map[i][j] != 0)
		{
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}
