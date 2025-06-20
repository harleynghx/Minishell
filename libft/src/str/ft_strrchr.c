/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:47:01 by zstenger          #+#    #+#             */
/*   Updated: 2025/06/10 19:21:17 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

/*
locates the last occurance of 'c' in the string pointed by 's'
(term null is part of the string) and returns a pointer to the character
or NULL if the char isn't found in the string
goes up in the string then checks the string from t he back
*/
char	*ft_strrchr(const char *s, int c)
{
	int	z;

	z = 0;
	while (s[z])
		z++;
	while (z >= 0)
	{
		if (s[z] == (char)c)
			return ((char *)(s + z));
		z--;
	}
	return (NULL);
}
