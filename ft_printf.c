/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotakagi <yotakagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/30 15:01:53 by yotakagi          #+#    #+#             */
/*   Updated: 2024/12/05 17:41:01 by yotakagi         ###   ########.fr       */
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

#include <stdio.h>

int	main(void)
{
	int				num;
	int				neg_num;
	char			c;
	char			*str;
	int				*ptr;
	unsigned int	u_num;
	char			*null_str;
	unsigned long	*null_ptr;
	char			long_str[] = "This is a really long string that might cause overflow if not handled properly by printf.";
	char			*infinite_loop_str;

	int a, b;
	a = 5, b = 10;
	// 1. 整数の表示
	num = 42;
	printf("printf: %d\n", num);
	ft_printf("ft_printf: %d\n", num);
	// 2. 負の整数の表示
	neg_num = -42;
	printf("printf: %d\n", neg_num);
	ft_printf("ft_printf: %d\n", neg_num);
	// 3. 文字の表示
	c = 'A';
	printf("printf: %c\n", c);
	ft_printf("ft_printf: %c\n", c);
	// 4. 文字列の表示
	str = "Hello, World!";
	printf("printf: %s\n", str);
	ft_printf("ft_printf: %s\n", str);
	// 5. ポインタの表示
	ptr = &num;
	printf("printf: %p\n", ptr);
	ft_printf("ft_printf: %p\n", ptr);
	// 6. 無符号整数の表示
	u_num = 12345;
	printf("printf: %u\n", u_num);
	ft_printf("ft_printf: %u\n", u_num);
	// 7. 16進数 (小文字) の表示
	printf("printf: %x\n", num);
	ft_printf("ft_printf: %x\n", num);
	// 8. 16進数 (大文字) の表示
	printf("printf: %X\n", num);
	ft_printf("ft_printf: %X\n", num);
	// 10. 複数の引数
	printf("printf: a = %d, b = %d\n", a, b);
	ft_printf("ft_printf: a = %d, b = %d\n", a, b);
	// 11. フォーマット指定子なし
	printf("printf: No format\n");
	ft_printf("ft_printf: No format\n");
	// 13. 不正なフォーマット指定子（%qなど）
	printf("printf: %%q\n");       // 不正なフォーマット指定子
	ft_printf("ft_printf: %%q\n"); // 不正なフォーマット指定子
	// 14. 未初期化のポインタ（NULL）
	null_str = NULL;
	printf("printf: %s\n", null_str);       // NULL ポインタを渡す
	ft_printf("ft_printf: %s\n", null_str); // NULL ポインタを渡す
	// 15. NULL を渡すときのポインタ表示（%p）
	null_ptr = NULL;
	printf("printf: %p\n", null_ptr);       // NULL ポインタ
	ft_printf("ft_printf: %p\n", null_ptr); // NULL ポインタ
	// 16. 不正な引数数（%dに対して引数が不足）
	printf("printf: %d\n", 42);       // 引数不足を防ぐ
	ft_printf("ft_printf: %d\n", 42); // 引数不足を防ぐ
	// 17. フォーマット文字列がNULL
	printf("printf: %s\n", (char *)NULL);       // NULL文字列を渡す
	ft_printf("ft_printf: %s\n", (char *)NULL); // NULL文字列を渡す
	// 18. 長すぎる文字列
	printf("printf: %s\n", long_str);
	ft_printf("ft_printf: %s\n", long_str);
	// 19. 無限ループを引き起こすケース（%sに対してNULL）
	infinite_loop_str = NULL;
	printf("printf: %s\n", infinite_loop_str);       // NULL文字列
	ft_printf("ft_printf: %s\n", infinite_loop_str); // NULL文字列
	return (0);
}
