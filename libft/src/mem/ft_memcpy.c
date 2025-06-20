/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:46:34 by zstenger          #+#    #+#             */
/*   Updated: 2025/06/10 19:21:40 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
copies 'n' bytes of memory from 'src' to 'dst', return dst
not recommended to use because dst and src can overlap and the behavior is
undefined
*/
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	count;
	char	*new_dst;
	char	*new_src;

	if (!dst && !src)
		return (NULL);
	new_dst = (char *)dst;
	new_src = (char *)src;
	count = 0;
	while (count < n)
	{
		new_dst[count] = new_src[count];
		count++;
	}
	return (dst);
}
