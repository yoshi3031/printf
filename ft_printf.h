/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yotakagi <yotakagi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 13:55:26 by takagiyoshi       #+#    #+#             */
/*   Updated: 2024/12/05 18:32:24 by yotakagi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>

int	ft_check(va_list args, char c);
int	ft_putadress(unsigned long nb);
int	ft_putchar(char c);
int	ft_puthex_m(unsigned int nb);
int	ft_puthex(unsigned long nb);
int	ft_putnbr(int nb);
int	ft_putunbr(unsigned int nb);
int	ft_putstr(char *str);

#endif