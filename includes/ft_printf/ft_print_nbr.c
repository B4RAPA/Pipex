/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:18:22 by lfabel            #+#    #+#             */
/*   Updated: 2024/09/16 10:28:41 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_print_nbr(int nb)
{
	int			counter;
	char		ch[16];
	int			a;
	long int	n;

	a = 0;
	n = nb;
	counter = 0;
	if (n == 0)
	{
		write (2, "0", 1);
		return (1);
	}
	if (n < 0)
	{
		n *= -1;
		write(2, "-", 1);
	}
	counter = array_laenge(n, counter);
	a = a + counter;
	ft_loop(n, counter, ch);
	if (nb < 0)
		a += 1;
	return (a);
}

void	ft_loop(long int n, int counter, char *ch)
{
	int	temp;
	int	a;

	a = counter;
	while (counter > 0)
	{
		temp = n % 10;
		n /= 10;
		ch [counter - 1] = temp + '0';
		counter --;
	}
	write (2, ch, a);
}

int	array_laenge( long int nb, int counter)
{
	int	a;

	while (nb >= 10)
	{
		a = nb / 10 ;
		nb = a ;
		counter++;
	}
	counter += 1;
	return (counter);
}
