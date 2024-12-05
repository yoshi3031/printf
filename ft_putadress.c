/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotakagi <yotakagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:51:21 by takagiyoshi       #+#    #+#             */
/*   Updated: 2024/12/05 18:33:34 by yotakagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadress(unsigned long nb)
{
	// int		re;
	// char	*base;
	// re = 0;
	// base = "0123456789abcdef";
	// if (nb >= 16)
	// {
	// 	re += ft_puthex(nb / 16);
	// 	re += ft_puthex(nb % 16);
	// }
	// else
	// 	re += ft_putchar(base[nb % 16]);
	// return (re);
	return (ft_puthex(nb));
}
