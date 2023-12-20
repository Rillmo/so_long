/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeunkim <hyeunkim@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 14:17:08 by hyeunkim          #+#    #+#             */
/*   Updated: 2023/10/18 19:56:19 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	i_to_arr(int n, char *result, size_t digit)
{
	if (!digit || result[digit - 1] == '-')
		return ;
	if (n < 0)
		result[digit - 1] = (n % 10) * -1 + '0';
	else
		result[digit - 1] = (n % 10) + '0';
	i_to_arr(n / 10, result, digit - 1);
}

static size_t	get_digit(int n)
{
	size_t	digit;

	digit = 0;
	if (n <= 0)
		digit++;
	while (n != 0)
	{
		digit++;
		n /= 10;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	size_t	digit;
	char	*result;

	digit = get_digit(n);
	result = (char *)ft_calloc(digit + 1, sizeof(char));
	if (!result)
		return (NULL);
	if (n < 0)
		result[0] = '-';
	i_to_arr(n, result, digit);
	return (result);
}
