/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_strchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 16:54:02 by liyu-her          #+#    #+#             */
/*   Updated: 2025/06/10 19:17:56 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fprintf.h"

char	*fpf_strchr(const char *s, int c)
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
