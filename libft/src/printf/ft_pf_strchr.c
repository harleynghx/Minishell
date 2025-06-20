/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_strchr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 19:46:42 by zstenger          #+#    #+#             */
/*   Updated: 2025/06/10 19:19:04 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

char	*ft_pf_strchr(const char *s, int c)
{
	int	z;

	z = 0;
	while (s[z])
	{
		if (s[z] == (char)c)
			return ((char *)(s + z));
		z++;
	}
	if (s[z] == (char)c)
		return ((char *)(s + z));
	return (NULL);
}
