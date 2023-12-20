/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:47:38 by junkim2           #+#    #+#             */
/*   Updated: 2023/11/24 16:06:05 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_game(t_mlx *mlx, int is_err, char *message)
{
	ft_lstclear(&(mlx->heap), &free);
	reset_mlx(mlx);
	if (is_err == 1)
	{
		write(1, "Error\n", 6);
		perror(message);
		exit(EXIT_FAILURE);
	}
	ft_putstr_fd(message, 1);
	exit (EXIT_SUCCESS);
}

/*	if content is null (error occurs) : call error_handler and return NULL
	if content is not null (no error) : add to heap,tosave and return 1 */
void	check_err(t_mlx *mlx, void *content, char *err_message, char **tosave)
{
	t_list	*new;

	if (content == NULL)
		exit_game(mlx, 1, err_message);
	new = ft_lstnew(content);
	ft_lstadd_front(&(mlx->heap), new);
	*tosave = content;
}

void	reset_mlx(t_mlx *mlx)
{
	mlx->heap = NULL;
	mlx->width = 0;
	mlx->height = 0;
	mlx->cat_loc.x = 0;
	mlx->cat_loc.y = 0;
	mlx->map = 0;
	mlx->log = 0;
	mlx->tuna_count = 0;
}
