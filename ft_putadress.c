/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takagiyoshiharu <takagiyoshiharu@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:51:21 by takagiyoshi       #+#    #+#             */
/*   Updated: 2024/12/05 16:16:52 by takagiyoshi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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
