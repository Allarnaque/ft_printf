/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 16:10:26 by adebert           #+#    #+#             */
/*   Updated: 2023/12/07 17:36:25 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H

# define FT_PRINTF_H

# include <unistd.h>

# include <stdlib.h>

#include <stdarg.h>

int     printf(char *format, ...);
int     check_format(char c, va_list ap);
size_t  ft_strlen(const char *s);
int     ft_putstr(char *s);
int	    ft_putchar(char c);
int	    ft_putnbr_decimal(int n, int i);
int	    ft_putnbr_hexa_min(int n, int i);
int	    ft_putnbr_hexa_maj(int n, int i);

#endif