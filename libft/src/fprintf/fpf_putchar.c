/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_putchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:19:11 by liyu-her          #+#    #+#             */
/*   Updated: 2025/05/31 18:19:12 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"../../includes/fprintf.h"

/*
writing chars and for calculating the length of the string
*/
void	fpf_putchar(char c, int *input_len)
{
	*input_len += write(STDERR_FILENO, &c, 1);
}
