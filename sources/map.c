/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 19:12:30 by junkim2           #+#    #+#             */
/*   Updated: 2023/11/30 13:20:52 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// check map path : need to get all 'C' and reach to 'E'
void	check_valid_path(char **map, t_location loc, int *result, int *count)
{
	const int	dx[4] = {0, 0, -1, 1};
	const int	dy[4] = {-1, 1, 0, 0};
	int			i;
	t_location	next_loc;

	i = 0;
	if (map[loc.y][loc.x] == '1')
		return ;
	if (map[loc.y][loc.x] != '0' && map[loc.y][loc.x] != '1' && \
		map[loc.y][loc.x] != 'C' && map[loc.y][loc.x] != 'X' && \
		map[loc.y][loc.x] != 'E' && map[loc.y][loc.x] != 'P')
		return ;
	while (i < 4)
	{	
		if (map[loc.y][loc.x] == 'E')
			*result = 1;
		if (map[loc.y][loc.x] == 'C')
			(*count)--;
		if (map[loc.y][loc.x] == '0' || map[loc.y][loc.x] == 'C')
			map[loc.y][loc.x] = '1';
		next_loc.x = loc.x + dx[i];
		next_loc.y = loc.y + dy[i];
		check_valid_path(map, next_loc, result, count);
		i++;
	}
}

// check map covered by '1'
int	check_wall(char **map, int height, int width)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if ((i == 0 || i == height - 1) && map[i][j] != '1')
				return (_ERROR);
			if ((j == 0 || j == width - 1) && map[i][j] != '1')
				return (_ERROR);
			j++;
		}
		i++;
	}
	return (1);
}

/*	[check resources]
	resource[3] means -> 0:E, 1:C, 2:P */
int	check_resources(char **map, int height, int width)
{
	int			i;
	int			j;
	int			resources[3];

	ft_bzero(resources, 3);
	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			if (map[i][j] == 'E')
				resources[0]++;
			else if (map[i][j] == 'C')
				resources[1]++;
			else if (map[i][j] == 'P')
				resources[2]++;
			j++;
		}
		i++;
	}
	if (resources[0] != 1 || resources[1] < 1 || resources[2] != 1)
		return (_ERROR);
	return (1);
}

/*	1. rectangle check 				...ok
	2. wall check					...ok
	3. valid path check				...ok
	4. resource check : 1E, 1C, 1P	...ok */
void	check_map(t_mlx *mlx)
{
	char	**cpy;
	int		i;
	int		result;
	int		count;

	cpy = copy_map(mlx->map, mlx->height);
	if (cpy == NULL)
		exit_game(mlx, 1, "(f)copy_map error");
	i = 0;
	while (mlx->map[i] != 0)
	{
		if ((int)ft_strlen(mlx->map[i]) != mlx->width)
			exit_game(mlx, 1, "map is not rectangle");
		i++;
	}
	if (!check_resources(mlx->map, mlx->height, mlx->width))
		exit_game(mlx, 1, "invalid amount of R or C or P");
	if (!check_wall(mlx->map, mlx->height, mlx->width))
		exit_game(mlx, 1, "map is not covered by wall");
	result = 0;
	count = count_c(mlx->map);
	check_valid_path(cpy, get_cat_loc(mlx->map), &result, &count);
	if (!(count == 0 && result == 1))
		exit_game(mlx, 1, "no valid path found");
}

// read map to array
void	read_map(t_mlx *mlx, int fd)
{
	char	*buff;
	char	*line;

	check_err(mlx, get_next_line(fd), "File read error", &buff);
	mlx->width = ft_strlen(buff) - 1;
	line = "";
	while (buff != NULL)
	{
		mlx->height++;
		check_err(mlx, ft_strjoin(line, buff), "(f)strjoin error", &line);
		buff = get_next_line(fd);
	}
	mlx->map = ft_split(line, '\n');
	if (mlx->map == NULL)
		exit_game(mlx, 1, "(f)ft_split error");
	check_map(mlx);
}
