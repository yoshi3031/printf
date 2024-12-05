/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takagiyoshiharu <takagiyoshiharu@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:53:21 by takagiyoshi       #+#    #+#             */
/*   Updated: 2024/12/05 16:16:37 by takagiyoshi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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
