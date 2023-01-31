/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbriglia <fbriglia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:45:58 by fbriglia          #+#    #+#             */
/*   Updated: 2023/01/31 17:15:04 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*noodle;

	if (*lst != 0)
	{
		noodle = ft_lstlast(*lst);
		noodle->next = new;
	}
	else
		*lst = new;
}
