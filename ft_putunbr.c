/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunbr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotakagi <yotakagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:53:50 by takagiyoshi       #+#    #+#             */
/*   Updated: 2024/12/05 16:33:22 by yotakagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
