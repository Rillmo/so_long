/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 23:35:04 by macbookpro        #+#    #+#             */
/*   Updated: 2023/11/23 21:52:34 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*error_handler(t_lst *lst)
{
	free(lst->buff);
	lst->buff = NULL;
	lst->current_size = 0;
	lst->total_size = 0;
	lst->flag = 0;
	return (NULL);
}

void	my_memmove(t_lst *lst, int idx)
{
	int	i;

	i = 0;
	while (lst->buff[idx] != 0)
	{
		lst->buff[i] = lst->buff[idx];
		i++;
		idx++;
	}
	lst->current_size = i;
	while (lst->buff[i] != 0)
		lst->buff[i++] = 0;
}

char	*get_left(t_lst *lst)
{
	char	*result;
	char	*pos;
	int		len;
	int		i;

	pos = my_strchr(lst->buff, '\n');
	if (lst->flag == 1 && pos == NULL)
	{
		result = my_strdup(lst->buff);
		if (result == NULL)
			return (error_handler(lst));
		return (result);
	}
	len = pos - lst->buff + 2;
	result = (char *)my_calloc(len, sizeof(char));
	if (result == NULL)
		return (error_handler(lst));
	i = 0;
	while (i < len - 1)
	{
		result[i] = lst->buff[i];
		i++;
	}
	my_memmove(lst, i);
	return (result);
}

char	*read_line(int fd, t_lst *lst)
{
	int		read_size;
	char	*tmp;

	if (lst->flag == 0 && lst->total_size - lst->current_size < BUFFER_SIZE)
	{
		tmp = alloc_double(lst);
		if (tmp == NULL)
			return (error_handler(lst));
		lst->buff = tmp;
	}
	read_size = 0;
	while (lst->total_size - lst->current_size >= BUFFER_SIZE && \
my_strchr(lst->buff, '\n') == NULL && lst->flag == 0)
	{
		read_size = read(fd, &(lst->buff[lst->current_size]), BUFFER_SIZE);
		if (read_size < 0)
			return (error_handler(lst));
		lst->current_size += read_size;
		if (read_size == 0)
			lst->flag = 1;
	}
	if (lst->flag == 0 && my_strchr(lst->buff, '\n') == NULL)
		return (read_line(fd, lst));
	return (lst->buff);
}

char	*get_next_line(int fd)
{
	static t_lst	arr[FD_LIMIT];
	char			*result;
	char			*err_flag;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	err_flag = read_line(fd, &arr[fd]);
	if (err_flag == NULL)
		return (NULL);
	if (arr[fd].flag == 1 && arr[fd].buff[0] == 0)
		return (error_handler(&arr[fd]));
	result = get_left(&arr[fd]);
	if (result == _ERROR)
		return (NULL);
	if (arr[fd].flag == 1)
		error_handler(&arr[fd]);
	return (result);
}
