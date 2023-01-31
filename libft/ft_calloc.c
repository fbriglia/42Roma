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

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;

	i = 0;
	ptr = NULL;
	if (nmemb * size < 4294967295)
	{
		ptr = (void *)malloc(nmemb * size);
		if (!ptr)
			return (NULL);
		ft_bzero(ptr, nmemb * size);
	}
	return (ptr);
}
