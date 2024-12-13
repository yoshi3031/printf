/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotakagi <yotakagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:01:53 by yotakagi          #+#    #+#             */
/*   Updated: 2024/12/13 16:17:52 by yotakagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		re;

	va_start(args, str);
	re = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			if (str[i + 1] != '\0')
				re += ft_check(args, str[++i]);
		}
		else
			re += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (re);
}

// #include <stdlib.h>

// int	main(void)
// {
// 	char	*null_str;
// 	int		x;

// 	// Integer test
// 	printf("printf: %d\n", 42);
// 	ft_printf("ft_printf: %d\n", 42);
// 	printf("printf: %d\n", -42);
// 	ft_printf("ft_printf: %d\n", -42);
// 	// Character test
// 	printf("printf: %c\n", 'A');
// 	ft_printf("ft_printf: %c\n", 'A');
// 	// String test
// 	printf("printf: %s\n", "Hello, world!");
// 	ft_printf("ft_printf: %s\n", "Hello, world!");
// 	null_str = NULL;
// 	printf("printf: %s\n", null_str);
// 	ft_printf("ft_printf: %s\n", null_str);
// 	// Pointer test
// 	x = 42;
// 	printf("printf: %p\n", &x);
// 	ft_printf("ft_printf: %p\n", &x);
// 	printf("printf: %p\n", null_str);
// 	ft_printf("ft_printf: %p\n", null_str);
// 	// Unsigned integer test
// 	printf("printf: %u\n", 42);
// 	ft_printf("ft_printf: %u\n", 42);
// 	// Hexadecimal test
// 	printf("printf: %x\n", 42);
// 	ft_printf("ft_printf: %x\n", 42);
// 	printf("printf: %X\n", 42);
// 	ft_printf("ft_printf: %X\n", 42);
// 	// Multiple arguments test
// 	printf("printf: %d %c %s\n", 42, 'A', "Hello");
// 	ft_printf("ft_printf: %d %c %s\n", 42, 'A', "Hello");
// 	// No format specifier
// 	printf("printf: Hello, world!\n");
// 	ft_printf("ft_printf: Hello, world!\n");
// 	// Invalid format specifier
// 	printf("printf: %%q\n");
// 	ft_printf("ft_printf: %%q\n");
// 	// Long string test
// 	printf("printf: %s\n",
// 		"This is a very long string to test the ft_printf implementation.");
// 	ft_printf("ft_printf: %s\n",
// 		"This is a very long string to test the ft_printf implementation.");
// 	return (0);
// }
