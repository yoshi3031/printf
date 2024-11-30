/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotakagi <yotakagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:01:53 by yotakagi          #+#    #+#             */
/*   Updated: 2024/11/30 19:40:29 by yotakagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdarg.h"
#include "stdio.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_check(va_list args, char c)
{
	int	re;

	re = 0;
	if (c == 'd' || c == 'i')
		re = ft_putnbr(va_arg(args, int));
}

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
#ifdef FT_PRINTF
# define F(...)                    \
	res = ft_printf(__VA_ARGS__); \
	printf("%d\n", res);
#else
# define F(...)                 \
	res = printf(__VA_ARGS__); \
	printf("%d\n", res);
#endif

int	main(void)
{
	int	res;

	F("Hello , %s \n", "world");
	F("The number is %s \n", "42");
	return (0);
}
