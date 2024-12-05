/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_m.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takagiyoshiharu <takagiyoshiharu@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:52:04 by takagiyoshi       #+#    #+#             */
/*   Updated: 2024/12/05 16:16:48 by takagiyoshi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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
