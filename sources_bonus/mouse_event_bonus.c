/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:52:43 by junkim2           #+#    #+#             */
/*   Updated: 2023/11/24 18:28:32 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	mouse_event(t_mlx *mlx)
{
	write(1, "exit\n", 5);
	reset_mlx(mlx);
	exit(EXIT_SUCCESS);
}
