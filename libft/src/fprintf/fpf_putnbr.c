/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fpf_putnbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:19:16 by liyu-her          #+#    #+#             */
/*   Updated: 2025/06/10 19:17:53 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fprintf.h"

/*
if the number is smaller than 0 print the minus sign and
take it off from the number by multiplying it by -1
and then print it after te sign with the 2nd if or the
else statement
*/
void	fpf_putnbr(long int number, int *input_len)
{
	if (number < 0)
	{
		fpf_putchar('-', input_len);
		number *= -1;
	}
	if (number > 9)
	{
		fpf_putnbr(number / 10, input_len);
		fpf_putchar(number % 10 + '0', input_len);
	}
	else
		fpf_putchar(number + '0', input_len);
}
