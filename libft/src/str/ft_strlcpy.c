/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:46:52 by zstenger          #+#    #+#             */
/*   Updated: 2025/06/10 19:21:10 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
copies from src to dst until size - 1 (for null) an returns the string
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	a;

	a = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (a < size - 1 && src[a])
	{
		dst[a] = src[a];
		a++;
	}
	dst[a] = 0;
	return (ft_strlen(src));
}
