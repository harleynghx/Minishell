/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprintf.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: liyu-her <liyu-her@student.42.kl>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/05 11:31:55 by zstenger          #+#    #+#             */
/*   Updated: 2025/05/31 18:17:07 by liyu-her         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FPRINTF_H
# define FPRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define HEX_LC "0123456789abcdef"
# define HEX_UC "0123456789ABCDEF"

int		p_err(const char *format, ...);

//utils
void	fpf_check_format(va_list *args, char conversion_type, int *input_len);
void	fprint_hex(unsigned long number, char *hex_format, int *input_len);
void	fpf_putchar(char c, int *input_len);
void	fpf_putstr(char *str, int *input_len);
void	fpf_putnbr(long int number, int *input_len);
char	*fpf_strchr(const char *s, int c);

#endif