/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adebert <adebert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 13:19:47 by adebert           #+#    #+#             */
/*   Updated: 2023/12/07 17:36:24 by adebert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr_decimal(int n, int i)
{
	char	c;

	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n >= 0 && n <= 9)
	{
		c = n + '0';
		write(1, &c, 1);
	}
	if (n > 9)
	{
		ft_putnbr_decimal(n / 10);
		ft_putnbr_decimal(n % 10);
	}
}

int	ft_putnbr_hexa_min(int n, int i)
{
	char	c;
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n > 15)
	{
		ft_putnbr_hexa_min(n / 16);
		ft_putnbr_hexa_min(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else 
			ft_putchar(n - 10 + 'a');
	}
}

int	ft_putnbr_hexa_maj(int n, int i)
{
	char	c;

	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n > 15)
	{
		ft_putnbr_hexa_maj(n / 16);
		ft_putnbr_hexa_maj(n % 16);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else 
			ft_putchar(n - 10 + 'A');
	}
}