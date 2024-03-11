/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: fbriglia <fbriglia@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2023/01/25 12:42:56 by fbriglia          #+#    #+#             */
/*   Updated: 2023/01/25 12:42:56 by fbriglia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*ptr;
	// size_t	i;

	// i = 0;
	if (nitems == SIZE_MAX && size == SIZE_MAX)
		return (NULL);
	ptr = (char *) malloc(nitems * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nitems * size);
	return ((void *) ptr);
}
