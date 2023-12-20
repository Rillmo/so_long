/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 20:14:22 by junkim2           #+#    #+#             */
/*   Updated: 2023/10/14 22:39:40 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*tmp;
	int		i;

	tmp = (char *)s;
	i = ft_strlen(tmp);
	if ((char)c == '\0')
		return (tmp + i);
	i--;
	while (i >= 0)
	{
		if (*(tmp + i) == (char)c)
			return (tmp + i);
		i--;
	}
	return (0);
}
