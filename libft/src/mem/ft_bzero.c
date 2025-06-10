/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:45:57 by zstenger          #+#    #+#             */
/*   Updated: 2025/06/10 19:21:32 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
erases the data in the n bytes of the memory starting at the location
pointed by 's' by writing zeros to that area'
	if (!s)
		return ;
*/
void	ft_bzero(void *s, size_t n)
{
	size_t	count;
	char	*c;

	count = 0;
	c = (char *)s;
	while (count < n)
	{
		c[count] = '\0';
		count++;
	}
}
