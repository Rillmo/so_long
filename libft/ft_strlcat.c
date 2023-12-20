/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 16:18:49 by junkim2           #+#    #+#             */
/*   Updated: 2023/10/14 17:14:09 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	idx;
	size_t	d_len;
	size_t	s_len;

	idx = 0;
	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	dst += d_len;
	if (dstsize < d_len)
		return (s_len + dstsize);
	while (idx + d_len + 1 < dstsize && src[idx])
	{
		dst[idx] = src[idx];
		idx++;
	}
	dst[idx] = 0;
	return (d_len + s_len);
}
