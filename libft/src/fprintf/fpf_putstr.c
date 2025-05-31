/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_putstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:19:20 by liyu-her          #+#    #+#             */
/*   Updated: 2025/05/31 18:19:21 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include	"../../includes/fprintf.h"

/*
print out null if no string after the format specifier
or print the length of the string until the terminating
null
*/
void	fpf_putstr(char *str, int *input_len)
{
	int	length;

	if (!str)
	{
		fpf_putstr("(null)", input_len);
		return ;
	}
	length = 0;
	while (str[length] != '\0')
	{
		fpf_putchar(str[length], input_len);
		length++;
	}
}
