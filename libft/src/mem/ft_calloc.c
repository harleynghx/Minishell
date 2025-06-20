/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:46:10 by zstenger          #+#    #+#             */
/*   Updated: 2025/06/10 19:21:36 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
allocates enough memory for 'count' objects that are
'size' bytes of memory and returns a pointer to the allocated memory
SIZE_MAX is the max value of type size_t and added for protection against
segmentation fault
max is added so calloc will work with empty string
*/
void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	max;

	max = size * count;
	ptr = malloc(max);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, max);
	return (ptr);
}
