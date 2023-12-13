/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_integer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakaro <anmakaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:56:38 by anmakaro          #+#    #+#             */
/*   Updated: 2023/12/13 12:56:39 by anmakaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(char *nbstr, int n, t_format flags)
{
	int	cum_len;

	cum_len = 0;
	if (n < 0)
	{
		if (flags.zero == 0 || flags.precision >= 0)
			cum_len += ft_print_c('-');
	}
	else if (flags.plus == 1 && flags.zero == 0)
		cum_len += ft_print_c('+');
	else if (flags.space == 1 && flags.zero == 0)
		cum_len += ft_print_c(' ');
	if (flags.precision >= 0)
		cum_len += ft_pad_width(flags.precision - 1,
				ft_strlen(nbstr) - 1, 1);
	cum_len += ft_print_str(nbstr);
	return (cum_len);
}

int	ft_print_sign(int n, t_format *flags)
{
	int	cum_len;

	cum_len = 0;
	if (n < 0 && flags->precision == -1)
	{
		cum_len += ft_print_c('-');
		flags->width--;
	}
	else if (flags->plus == 1)
		cum_len += ft_print_c('+');
	else if (flags->space == 1)
	{
		cum_len += ft_print_c(' ');
		flags->width--;
	}
	return (cum_len);
}

int	ft_print_integer(char *nbstr, int n, t_format flags)
{
	int	cum_len;

	cum_len = 0;
	if (flags.zero == 1)
		cum_len += ft_print_sign(n, &flags);
	if (flags.left == 1)
		cum_len += ft_print_int(nbstr, n, flags);
	if (flags.precision >= 0 && (size_t)flags.precision < ft_strlen(nbstr))
		flags.precision = ft_strlen(nbstr);
	if (flags.precision >= 0)
	{
		flags.width -= flags.precision;
		if (n < 0 && flags.left == 0)
			flags.width -= 1;
		cum_len += ft_pad_width(flags.width, 0, 0);
	}
	else
		cum_len += ft_pad_width(flags.width - flags.plus - flags.space,
				ft_strlen(nbstr), flags.zero);
	if (flags.left == 0)
		cum_len += ft_print_int(nbstr, n, flags);
	return (cum_len);
}

int	ft_print_decimal_integer(int n, t_format flags)
{
	char	*nmbstr;
	long	nb;
	int		cum_len;

	nb = n;
	cum_len = 0;
	if (nb < 0)
	{
		nb *= -1;
		if (flags.zero == 0)
			flags.width--;
	}
	if (flags.precision == 0 && n == 0)
	{
		cum_len += ft_pad_width(flags.width, 0, 0);
		return (cum_len);
	}
	nmbstr = ft_itoa_v(nb);
	if (!nmbstr)
		return (0);
	cum_len += ft_print_integer(nmbstr, n, flags);
	free(nmbstr);
	return (cum_len);
}
