/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putadress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: takagiyoshiharu <takagiyoshiharu@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:51:21 by takagiyoshi       #+#    #+#             */
/*   Updated: 2024/12/06 00:59:18 by takagiyoshi      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putadress(unsigned long nb)
{
	if(nb == 0)
		return (ft_putstr("(nil)"));
	ft_putstr("0x");
	return (ft_puthex(nb));
}
