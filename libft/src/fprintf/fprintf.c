/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fprintf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: harleyng <harleyng@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/31 18:24:37 by liyu-her          #+#    #+#             */
/*   Updated: 2025/06/10 19:17:59 by harleyng         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/fprintf.h"

/*
@param format->char string which contains plain chars, escape sequences
and format specifications
if there is	format(input) checks the type of it
if its a plain text, simply print it out
else checks for the type of conversion and applies it and print the result
*/

int	p_err(const char *format, ...)
{
	va_list	args;
	int		index;
	int		*input_len;
	int		output;

	va_start(args, format);
	output = 0;
	index = 0;
	input_len = &output;
	if (!format || (format[index] == '%' && !format[index + 1]))
		return (-1);
	while (format[index] != '\0')
	{
		if (format[index] == '%' && *fpf_strchr("cspdiuxX%", format[index + 1]))
		{
			index++;
			fpf_check_format(&args, format[index], input_len);
		}
		else
			output += write(STDERR_FILENO, &format[index], 1);
		index++;
	}
	va_end(args);
	return (output);
}

/*
int	main(void)
{
	int				ret1;
	int				ret2;
	char			str1[] = "This is the first format specifier#&.';?/!\n";
	int				i;
	int				j;
	int				l;
	int				*ptr1;
	int				*ptr2;
	int				*ptr3;
	int				*ptr4;
	unsigned int	k;

	ft_printf("%% %");
	ret1 = ft_printf("%s", str1);
	ret2 = printf("%s", str1);
	printf("Here the return (of ft_printf: 	%d\n", ret1));
	printf("Here the return (of printf: 	%d\n", ret2));
	i = -2147483648;
	j = 2147483647;
	l = 0;
	ptr1 = &i;
	ptr2 = &j;
	ptr3 = &l;
	ptr4 = NULL;
	ret1 = ft_printf("%p\n%p\n%p\n%p\n", ptr1, ptr2, ptr3, ptr4);
	ret2 = printf("%p\n%p\n%p\n%p\n", ptr1, ptr2, ptr3, ptr4);
	printf("Here the return (of ft_printf: 	%d\n", ret1));
	printf("Here the return (of printf: 	%d\n", ret2));
	i = -2147483648;
	j = 2147483647;
	l = 0;
	ret1 = ft_printf("%d\n%d\n%d\n", i, j, l);
	ret2 = printf("%d\n%d\n%d\n", i, j, l);
	printf("Here the return (of ft_printf: 	%d\n", ret1));
	printf("Here the return (of printf: 	%d\n", ret2));
	ret1 = ft_printf("%i\n%i\n%i\n", i, j, l);
	ret2 = printf("%i\n%i\n%i\n", i, j, l);
	printf("Here the return (of ft_printf: 	%d\n", ret1));
	printf("Here the return (of printf: 	%d\n", ret2));
	i = -2147483648;
	j = 0;
	k = 4294967295;
	ret1 = ft_printf("%u\n%u\n%u\n", i, j, k);
	ret2 = printf("%u\n%u\n%u\n", i, j, k);
	printf("Here the return (of ft_printf: 	%d\n", ret1));
	printf("Here the return (of printf: 	%d\n", ret2));
	i = -2147483648;
	j = 0;
	k = 42949627;
	ret1 = ft_printf("%x\n%x\n%x\n", i, j, k);
	ret2 = printf("%x\n%x\n%x\n", i, j, k);
	printf("Here the return (of ft_printf: 	%d\n", ret1));
	printf("Here the return (of printf: 	%d\n", ret2));
	ret1 = ft_printf("%X\n%X\n%X\n", i, j, k);
	ret2 = printf("%X\n%X\n%X\n", i, j, k);
	printf("Here the return (of ft_printf: 	%d\n", ret1));
	printf("Here the return (of printf: 	%d\n", ret2));
	ret1 = ft_printf("%% %%%% %%\n");
	ret2 = printf("%% %%%% %%\n");
	printf("Here the return (of ft_printf: 	%d\n", ret1));
	printf("Here the return (of printf: 	%d\n\n\n", ret2));
	printf("CHECKING FOR LEAKS:\n\n");
	system("leaks a.out");
	return (0);
}
*/