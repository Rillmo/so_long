/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: minjacho <minjacho@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 14:32:24 by minjacho          #+#    #+#             */
/*   Updated: 2023/10/14 15:22:26 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*tmp_d;
	unsigned char	*tmp_s;
	size_t			idx;

	idx = 0;
	tmp_d = (unsigned char *)dst;
	tmp_s = (unsigned char *)src;
	if (!dst && !src)
		return (dst);
	while (idx < n)
	{
		tmp_d[idx] = tmp_s[idx];
		idx++;
	}
	return (dst);
}
