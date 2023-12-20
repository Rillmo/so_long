/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42seoul.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:20:12 by junkim2           #+#    #+#             */
/*   Updated: 2023/10/19 18:00:17 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	str_to_word(char *str, char c, size_t org_len)
{
	size_t	idx;
	size_t	word_cnt;

	idx = 0;
	word_cnt = 0;
	while (idx < org_len)
	{
		if (str[idx] != c)
		{
			word_cnt++;
			while (idx < org_len && str[idx] != c)
				idx++;
		}
		else
		{	
			str[idx] = 0;
			idx++;
		}
	}
	return (word_cnt);
}

static char	**clean(char **str_arr, char *str, size_t size)
{
	size_t	idx;

	idx = 0;
	while (idx < size)
	{
		free(str_arr[idx]);
		str_arr[idx] = NULL;
		idx++;
	}
	free(str_arr);
	free(str);
	str = NULL;
	return (NULL);
}

static char	**str_to_arr(char **result, char *str, size_t org_len)
{
	size_t	idx;
	size_t	word_idx;

	idx = 0;
	word_idx = 0;
	while (idx < org_len)
	{
		if (str[idx])
		{
			result[word_idx] = ft_strdup(&str[idx]);
			if (!result[word_idx])
			{
				clean(result, str, word_idx);
				return (NULL);
			}
			word_idx++;
			while (str[idx] && idx < org_len)
				idx++;
		}
		else
			idx++;
	}
	free(str);
	return (result);
}

char	**ft_split(char const *s, char c)
{
	size_t	words;
	size_t	len;
	char	*temp;
	char	**result;

	len = ft_strlen(s);
	temp = ft_strdup(s);
	if (!temp)
		return (NULL);
	words = str_to_word(temp, c, len);
	result = (char **)ft_calloc(words + 1, sizeof(char *));
	if (!result)
	{
		free(temp);
		temp = NULL;
		return (NULL);
	}
	return (str_to_arr(result, temp, len));
}
