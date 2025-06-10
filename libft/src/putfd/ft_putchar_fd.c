/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 16:13:14 by zstenger          #+#    #+#             */
/*   Updated: 2025/06/10 19:15:49 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

// outputs the char 'c' to the given file descriptor 'fd'
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
