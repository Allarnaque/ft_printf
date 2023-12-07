/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:21:49 by adebert           #+#    #+#             */
/*   Updated: 2023/12/07 23:05:31 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_int(int n, int sign)
{
	int	len_int;

	len_int = 0;
	if (n == 0)
		len_int = 1;
	if (sign == -1)
		len_int++;
	while (n > 0)
	{
		n /= 10;
		len_int++;
	}
	return (len_int);
}

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

	if (!s)
		return (write(1, "(null)", 6));
	
	i = ft_strlen(s);
	write(1, s, i);
    return (i);
}

int    check_format(char c, va_list ap)
{
    int count;

    count = 0;
    if (c == 's')
        count = ft_putstr(va_arg(ap, char *));
    else if (c == 'd' || c == 'i')
        count = ft_putnbr_decimal(va_arg(ap, int));
	else if (c == 'u')
		count = ft_putnbr_unsigned(va_arg(ap, unsigned int));
    else if (c == 'x' || c == 'p')
		count = ft_putnbr_hexa(va_arg(ap, int), 0);
	else if (c == 'X')
		count = ft_putnbr_hexa(va_arg(ap, int), 1);
    else if (c == 'c')
        count = ft_putchar(va_arg(ap, int));
    else if (c == '%')
        count = write (1, "%", 1);
    else
        return (0);
    return (count);
}

int ft_printf(const char *format, ...)
{
    va_list ap;
    int     i;
    int     count;

    va_start(ap, format);
	if (!format)
		return (-1);
    count = 0;
    i = 0;
    while(format[i])
    {
        if (format[i] == '%')
        {
            count += check_format(format[i + 1], ap);
            i++;
        }
        else
		{
			write (1, &format[i], 1);
			count++;
		}
        i++;
    }
    va_end(ap);
    return (count);
}

/* int main()
{
  int test = -500;
   //char c = '%';
    //char str[5] = "Hello";

   	printf("len = %d\n",ft_printf("%d", test));

    return (0);
} */