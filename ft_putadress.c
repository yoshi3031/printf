/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotakagi <yotakagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:51:21 by takagiyoshi       #+#    #+#             */
/*   Updated: 2024/12/13 16:28:15 by yotakagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadress(unsigned long nb)
{
	int	re;

	re = 0;
	if (nb == 0)
		return (ft_putstr("(nil)"));
	re += ft_putstr("0x");
	return (re + (ft_puthex(nb)));
}
