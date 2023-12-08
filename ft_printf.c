/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:21:49 by adebert           #+#    #+#             */
/*   Updated: 2023/12/08 14:50:36 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_int(int n, int sign)
{
	int	len_int;
  
	len_int = 0;
	if (n == 0)
		len_int = 1;
	if (sign == 1)
		len_int++;
	while (n > 0)
	{
		n /= 10;
		len_int++;
	}
	return (len_int);
}

int	ft_len_unsigned_int(unsigned int n, int sign)
{
	int	len_int;

	len_int = 0;
	if (n == 0)
		len_int = 1;
	if (sign == 1)
		len_int++;
	while (n > 0)
	{
		n /= 10;
		len_int++;
	}
	return (len_int);
}

int	ft_len_hexa(unsigned long n)
{
	int	len_int;

	len_int = 0;
	if (n == 0)
		len_int = 1;
	while (n > 0)
	{
		n /= 16;
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
    int sign;

    sign = 0;
    count = 0;
    if (c == 's')
        count = ft_putstr(va_arg(ap, char *));
    else if (c == 'd' || c == 'i')
        count = ft_putnbr_decimal(va_arg(ap, int), sign);
	else if (c == 'u')
		count = ft_putnbr_unsigned(va_arg(ap, unsigned int), sign);
    else if (c == 'x')
		count = ft_putnbr_hexa(va_arg(ap, int), 0);
	else if (c == 'X')
		count = ft_putnbr_hexa(va_arg(ap, int), 1);
	else if (c == 'p')
	{
		count = write(1, "0x", 2);
		count += ft_putnbr_ptr(va_arg(ap, unsigned long));
	}
    else if (c == 'c')
        count = ft_putchar(va_arg(ap, int));
    else if (c == '%')
        count = write (1, "%", 1);
    return (count);
}

int		check_index(char format)
{
	if (format == 'i' || format == 'd' || format == 's' || format == 'x'
		|| format == 'X' || format == 'u' || format == '%' 
		|| format == 'p' || format == 'c')
		return (1);
	return (0);
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
        if (format[i] == '%' && check_index(format[i + 1]))
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
  int test = 10;
  void *ptr;

  ptr = &test;
   //char c = '%';
    //char str[5] = "Hello";

    printf("len = %d\n",printf("%p", ptr));
   	printf("len = %d\n",ft_printf("%p", ptr));

    return (0);
} */