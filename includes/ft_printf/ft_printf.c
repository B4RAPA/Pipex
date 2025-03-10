/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 12:56:18 by lfabel            #+#    #+#             */
/*   Updated: 2024/09/16 10:28:58 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf.h"

int	ft_printf(const char *c, ...)
{
	size_t	i;
	size_t	num_args;
	int		count;
	va_list	args;

	num_args = ft_strlen_printf(c);
	i = 0;
	count = 0;
	va_start(args, c);
	while (i < num_args)
	{
		if (c[i] == '%')
		{
			count += check_input(c[i + 1], args);
			i++;
		}
		else
			count += ft_print_char(c[i]);
		i++;
	}
	va_end(args);
	return (count);
}

int	check_input(const char c, va_list args)
{
	int	count;

	count = 0;
	if (c == 'd' || c == 'i')
		count += ft_print_nbr(va_arg(args, int));
	if (c == 'c')
		count += ft_print_char(va_arg(args, int));
	if (c == 's')
		count += ft_print_str(va_arg(args, const char *));
	if (c == '%')
		count += write(2, "%", 1);
	if (c == 'u')
		count += ft_print_unsigned(va_arg(args, unsigned int));
	if (c == 'x' || c == 'X')
		count += ft_print_hex(va_arg(args, int), c);
	if (c == 'p')
		count += ft_print_ptr((unsigned long)va_arg(args, void *));
	return (count);
}

// int main(void)
// {
// 	int count;

// 	count = 0;
// 	count += ft_printf(" %p ", -1);

// 	return (0);
// }