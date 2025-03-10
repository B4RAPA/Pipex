/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 12:12:51 by lfabel            #+#    #+#             */
/*   Updated: 2024/09/16 10:27:36 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_ptr_hex(unsigned long int nbr, char *base)
{
	char			str[32];
	int				i;
	int				counter;

	i = 0;
	counter = 0;
	while (nbr >= 16)
	{
		str[i++] = base[(nbr % 16)];
		nbr /= 16;
		counter ++;
	}
	if (nbr < 16)
		str[i++] = base[nbr];
	counter += 1;
	ft_put_ptr(str, i);
	return (counter);
}

void	ft_put_ptr(char *str, int i)
{
	i -= 1;
	while (i >= 0)
		write (2, &str[i--], 1);
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	counter;

	counter = 0;
	if (!ptr)
	{
		counter += write (2, "(nil)", 5);
		return (counter);
	}
	counter += write(2, "0x", 2);
	if (ptr)
		counter += ft_ptr_hex(ptr, "0123456789abcdef");
	return (counter);
}
