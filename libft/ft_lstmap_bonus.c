/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 20:39:59 by junkim2           #+#    #+#             */
/*   Updated: 2023/10/19 20:58:25 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_null_checker(t_list *lst, void (*del)(void *), void *value)
{
	if (value == 0)
	{
		ft_lstclear(&lst, del);
		return (0);
	}
	return (1);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cur;
	t_list	*newnode;
	t_list	*newlst;
	void	*value;

	newlst = 0;
	cur = lst;
	while (cur != 0)
	{
		value = f(cur->content);
		if (ft_null_checker(newlst, del, value) == 0)
			return (0);
		newnode = ft_lstnew(value);
		if (ft_null_checker(newlst, del, newnode) == 0)
		{
			free(value);
			return (0);
		}
		ft_lstadd_back(&newlst, newnode);
		cur = cur->next;
	}
	return (newlst);
}
