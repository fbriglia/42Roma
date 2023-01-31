/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <fbriglia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 18:36:30 by fbriglia          #+#    #+#             */
/*   Updated: 2023/01/31 18:50:14 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*copy;
	t_list	*temp;

	if (!lst)
		return (0);
	copy = 0;
	while (lst)
	{
		temp = ft_lstnew(f(lst->content));
		if (temp == NULL)
		{
			ft_lstclear(&temp, *del);
			return (0);
		}
		ft_lstadd_back(&copy, temp);
		lst = lst->next;
	}
	return (copy);
}
