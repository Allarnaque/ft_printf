/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:21:49 by adebert           #+#    #+#             */
/*   Updated: 2023/12/07 17:36:21 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t  ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int    ft_putstr(char *s)
{
	size_t	i;

	i = ft_strlen(s);
	write(1, s, i);
    return (i);
}

int    check_format(char c, va_list ap)
{
    int i;

    i = 0;
    if (c == 's')
        i = ft_putstr(va_arg(ap, char *));
    else if (c == 'd' || c == 'i' || c == 'u')
        i = ft_putnbr_decimal(va_arg(ap, int));
    else if (c == 'x' || c == 'X' || c == 'p')
    {
        if (c == 'x' || c == 'p')
            i = ft_putnbr_hexa_min(va_arg(ap, int));
        if (c == 'X')
            i = ft_putnbr_hexa_maj(va_arg(ap, int));
    }
    else if (c == 'c')
        i = ft_putchar(va_arg(ap, int));
    else if (c == '%')
        i = write (1, "%", 1);
    else
        return (0);
    return (i + 1);
}

int ft_printf(char *format, ...)
{
    va_list ap;
    int     i;
    int     count;

    va_start(ap, format);
    count = 0;
    i = 0;
    while(format[i])
    {
        if (format[i] == '%')
        {
            count += check_format(format[i + 1], ap);
            i++;
        }
        if (format[i])
            write (1, &format[i], 1);
        i++;
    }
    va_end(ap);
    return (i);
}

int main()
{
    int test = -500;
   //char c = '%';
    //char str[5] = "Hello";

    int t_printf;
    int t_ft_printf;

    t_printf = printf("PRINTF -> %u\n", test);

    t_ft_printf = ft_printf("PRINTF -> %u\n", test);

    printf("T_PRINTF -> %d\n", t_printf);
    printf("T_FT_PRINTF -> %d\n", t_ft_printf);
    return (0);
}