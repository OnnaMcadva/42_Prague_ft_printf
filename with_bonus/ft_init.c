/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:56:48 by anmakaro          #+#    #+#             */
/*   Updated: 2024/05/27 15:48:25 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_init_format(char format, va_list args, t_format flags)
{
	int	cum_len;

	cum_len = 0;
	if (format == 'c')
		cum_len += ft_print_char(va_arg(args, int), flags);
	else if (format == 's')
		cum_len += ft_print_string(va_arg(args, const char *), flags);
	else if (format == 'p')
		cum_len
			+= ft_print_pointer((unsigned long int)va_arg(args, void *), flags);
	else if (format == 'd' || format == 'i')
		cum_len
			+= ft_print_decimal_integer(va_arg(args, int), flags);
	else if (format == 'u')
		cum_len
			+= ft_print_unsigned_decimal(va_arg(args, unsigned int), flags);
	else if (format == 'X')
		cum_len
			+= ft_print_hexadecimal(va_arg(args, unsigned int), 1, flags);
	else if (format == 'x' )
		cum_len
			+= ft_print_hexadecimal(va_arg(args, unsigned int), 0, flags);
	else if (format == '%')
		cum_len += ft_print_char('%', flags);
	return (cum_len);
}

int	ft_init_flags(const char *str, int i, va_list args, t_format *flags)
{
	while (str[++i] && ft_isflag(str[i]))
	{
		if (str[i] == '-')
			*flags = ft_flag_left(*flags);
		if (str[i] == '#')
			flags->hash = 1;
		if (str[i] == ' ')
			flags->space = 1;
		if (str[i] == '+')
			flags->plus = 1;
		if (str[i] == '0' && flags->left == 0 && flags->width == 0)
			flags->zero = 1;
		if (str[i] == '.')
			i = ft_flag_precision(str, i, args, flags);
		if (str[i] == '*')
			*flags = ft_flag_width(args, *flags);
		if (ft_isdigit(str[i]))
			*flags = ft_flag_digit(str[i], *flags);
		if (ft_isspec(str[i]))
		{
			flags->spec = str[i];
			break ;
		}
	}
	return (i);
}
