/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotakagi <yotakagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:50:58 by takagiyoshi       #+#    #+#             */
/*   Updated: 2024/12/05 18:27:47 by yotakagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
