/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takagiyoshiharu <takagiyoshiharu@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:01:53 by yotakagi          #+#    #+#             */
/*   Updated: 2024/12/05 16:16:59 by takagiyoshi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"


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
