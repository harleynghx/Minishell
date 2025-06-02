/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnlinelen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:08:33 by liyu-her          #+#    #+#             */
/*   Updated: 2025/05/27 14:08:33 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_gnlinelen(const char *line)
{
	size_t	count;

	count = 0;
	while (line[count] != '\0' && line[count] != '\n')
	{
		count++;
	}
	return (count);
}
