/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:19:47 by adebert           #+#    #+#             */
/*   Updated: 2023/12/07 23:06:49 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr_unsigned(unsigned int n)
{
	char	c;

	if (n <= 9)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	if (n > 9)
	{
		ft_putnbr_decimal(n / 10);
		ft_putnbr_decimal(n % 10);
	}
	return (ft_len_int(n, 0));
}

int	ft_putnbr_decimal(int n)
{
	char	c;
	int		sign;

	sign = 0;
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		sign = -1;
	}
	if (n <= 9)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	if (n > 9)
	{
		ft_putnbr_decimal(n / 10);
		ft_putnbr_decimal(n % 10);
	}
	return (ft_len_int(n, sign));
}

int	ft_putnbr_hexa(int n, int caps)
{
	int		sign;

	sign = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		sign = -1;
	}
	if (n >= 16)
	{
		ft_putnbr_hexa(n / 16, caps);
		ft_putnbr_hexa(n % 16, caps);
	}
	else
	{
			if (n <= 9)
				ft_putchar(n + '0');
			else
			{
				if (caps == 0)
					ft_putchar(n - 10 + 'a');
				else if (caps == 1)
					ft_putchar(n - 10 + 'A');	
			}
	}
	return (ft_len_int(n, sign));
}