/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:56:48 by junkim2           #+#    #+#             */
/*   Updated: 2023/10/18 20:57:07 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_all(char *arr, int idx, int fd)
{
	while (idx >= 0)
	{
		if (arr[idx] != 0)
			ft_putchar_fd(arr[idx], fd);
		idx--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	num;
	char	arr[11];
	int		conv_num;
	int		idx;

	idx = 0;
	num = n;
	if (n < 0)
	{
		num *= -1;
		ft_putchar_fd('-', fd);
	}
	while (1)
	{
		conv_num = num % 10;
		arr[idx++] = conv_num + '0';
		if (num / 10 == 0)
			break ;
		num /= 10;
	}
	print_all(arr, idx - 1, fd);
}
