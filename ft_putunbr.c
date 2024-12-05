/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takagiyoshiharu <takagiyoshiharu@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:53:50 by takagiyoshi       #+#    #+#             */
/*   Updated: 2024/12/05 16:16:42 by takagiyoshi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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
