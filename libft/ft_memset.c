/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 14:26:08 by junkim2           #+#    #+#             */
/*   Updated: 2023/10/14 22:48:53 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	value;
	size_t			i;
	unsigned char	*arr;

	value = (unsigned char)c;
	arr = (unsigned char *)b;
	i = 0;
	while (i < len)
	{
		*(arr + i) = value;
		i++;
	}
	return (arr);
}
