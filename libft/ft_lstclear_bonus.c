/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: junkim2 <junkim2@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 19:39:26 by junkim2           #+#    #+#             */
/*   Updated: 2023/10/18 20:31:13 by junkim2          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*delnode;
	t_list	*delnode_next;

	if (lst == 0)
		return ;
	delnode = *lst;
	while (delnode != 0)
	{		
		delnode_next = delnode->next;
		ft_lstdelone(delnode, del);
		delnode = delnode_next;
	}
	*lst = 0;
}
