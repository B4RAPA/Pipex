/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabel <lfabel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 09:56:13 by lfabel            #+#    #+#             */
/*   Updated: 2024/09/16 09:41:41 by lfabel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *c, ...);

int		ft_print_nbr(int nb);
int		ft_print_char(const char c);
int		ft_print_str(const char *str);
int		ft_print_unsigned(unsigned int n);
int		ft_print_hex(unsigned int n, char c);
int		ft_print_ptr(unsigned long long ptr);

int		check_input(const char c, va_list args);
int		array_laenge(long int nb, int counter);
int		ft_return_hex(char *str, int i);
int		ft_num_len(unsigned int n);
void	ft_loop(long int n, int counter, char *ch);
void	ft_put_ptr(char *str, int i);
size_t	ft_strlen_printf(char const *str);

#endif