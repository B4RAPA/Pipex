/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 09:59:59 by lfabel            #+#    #+#             */
/*   Updated: 2024/09/16 10:27:08 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	char			str[32];
	int				i;
	unsigned int	nb;
	int				counter;

	nb = nbr;
	i = 0;
	counter = 0;
	if (nb == 0)
	{
		write (2, "0", 1);
		counter += 1;
	}
	while (nb > 0)
	{
		str[i++] = base[(nb % 16)];
		nb /= 16;
	}
	counter += ft_return_hex(str, i);
	return (counter);
}

int	ft_return_hex(char *str, int i)
{
	int	counter;
	int	n;

	n = i - 1;
	counter = i;
	while (n >= 0)
	{
		write (2, &str[n--], 1);
	}
	return (counter);
}

int	ft_print_hex(unsigned int n, char c)
{
	int	counter;

	counter = 0;
	if (c == 'x')
		counter += ft_putnbr_base(n, "0123456789abcdef");
	if (c == 'X')
		counter += ft_putnbr_base(n, "0123456789ABCDEF");
	return (counter);
}
