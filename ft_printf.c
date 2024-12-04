/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotakagi <yotakagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:01:53 by yotakagi          #+#    #+#             */
/*   Updated: 2024/12/04 15:18:51 by yotakagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdarg.h"
#include "stdio.h"
#include "unistd.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(int nb)
{
	int	r;

	r = 0;
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		r += (write(1, "-", 1));
		nb *= -1;
	}
	if (nb > 9)
	{
		r += ft_putnbr(nb / 10);
		r += ft_putnbr(nb % 10);
	}
	else
		r += ft_putchar(nb + 48);
	return (r);
}

int	ft_putunbr(unsigned int nb)
{
	unsigned int	re;

	re = 0;
	if (nb > 9)
	{
		re += ft_putunbr(nb / 10);
		re += ft_putunbr(nb % 10);
	}
	else
		re += ft_putchar(nb + 48);
	return (re);
}

int	ft_putstr(char *str)
{
	int	i;

	if (str == NULL)
		return (write(1, "(null)", 6));
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int	ft_puthex(unsigned int nb)
{
	int		re;
	char	*base;

	re = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		re += ft_puthex(nb / 16);
		re += ft_puthex(nb % 16);
	}
	else
		re += ft_putchar(base[nb % 16]);
	return (re);
}

int	ft_puthex_m(unsigned int nb)
{
	int		re;
	char	*base;

	re = 0;
	base = "0123456789ABCDEF";
	if (nb >= 16)
	{
		re += ft_puthex_m(nb / 16);
		re += ft_puthex_m(nb % 16);
	}
	else
		re += ft_putchar(base[nb % 16]);
	return (re);
}

int	ft_putadress(unsigned long nb)
{
	int		re;
	char	*base;

	re = 0;
	base = "0123456789abcdef";
	if (nb >= 16)
	{
		re += ft_putadress(nb / 16);
		re += ft_putadress(nb % 16);
	}
	else
		re += ft_putchar(base[nb % 16]);
	return (re);
}

int	ft_check(va_list args, char c)
{
	int	re;

	re = 0;
	if (c == 'd' || c == 'i')
		re = ft_putnbr(va_arg(args, int));
	else if (c == 'c')
		re = ft_putchar(va_arg(args, int));
	else if (c == 's')
		re = ft_putstr(va_arg(args, char *));
	else if (c == 'x')
		re = ft_puthex(va_arg(args, unsigned int));
	else if (c == 'X')
		re = ft_puthex_m(va_arg(args, unsigned int));
	else if (c == 'p')
	{
		re = ft_putstr("0x");
		re += ft_putadress(va_arg(args, unsigned long));
	}
	else if (c == 'u')
		re = ft_putunbr(va_arg(args, unsigned int));
	else if (c == '%')
		return (ft_putchar('%'));
	return (re);
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

	// 基本的な文字列
	F("Hello, world!\n");
	F("Testing %s.\n", "string substitution");
	F("Empty string: [%s]\n", "");
	// 文字
	F("Character: [%c]\n", 'A');
	F("Multiple chars: [%c] [%c] [%c]\n", 'x', 'y', 'z');
	// 整数
	F("Positive integer: [%d]\n", 42);
	F("Negative integer: [%d]\n", -42);
	F("Zero: [%d]\n", 0);
	F("Large integer: [%d]\n", 2147483647);
	F("Small integer: [%d]\n", (int)-2147483648);
	// 符号なし整数
	F("Unsigned integer: [%u]\n", 42U);
	F("Max unsigned integer: [%u]\n", 4294967295U);
	F("Zero unsigned integer: [%u]\n", 0U);
	// 16進数（小文字）
	F("Hex lowercase: [%x]\n", 255);
	F("Hex lowercase (zero): [%x]\n", 0);
	F("Hex lowercase (large): [%x]\n", 4294967295U);
	// 16進数（大文字）
	F("Hex uppercase: [%X]\n", 255);
	F("Hex uppercase (zero): [%X]\n", 0);
	F("Hex uppercase (large): [%X]\n", 4294967295U);
	// ポインタ
	F("Pointer: [%p]\n", (void *)0x12345678);
	F("Null pointer: [%p]\n", (void *)0);
	// パーセント記号
	F("Literal percent: [%%]\n");
	// 混合フォーマット
	F("Mixed: %d %u %x %X %p %s\n", 42, 42U, 255, 255, (void *)0x12345678,
		"test");
	// エラーケース（特殊文字）
	F("Special characters: [\\n] [\\t] [\\0]\n");
	F("Partial format specifier: [%%]\n");
	return (0);
}
