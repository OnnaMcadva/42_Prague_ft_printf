/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakaro <anmakaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:57:10 by anmakaro          #+#    #+#             */
/*   Updated: 2023/12/13 12:57:11 by anmakaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_strfl(const char *str, t_format flags)
{
	int	cum_len;

	cum_len = 0;
	if (flags.precision >= 0)
	{
		cum_len += ft_pad_width(flags.precision, ft_strlen(str), 0);
		cum_len += ft_print_prec(str, flags.precision);
	}
	else
		cum_len += ft_print_prec(str, ft_strlen(str));
	return (cum_len);
}

int	ft_print_string(const char *str, t_format flags)
{
	int	cum_len;

	cum_len = 0;
	if (str == NULL && flags.precision >= 0 && flags.precision < 6)
	{
		cum_len += ft_pad_width(flags.width, 0, 0);
		return (cum_len);
	}
	if (str == NULL)
		str = "(null)";
	if (flags.precision >= 0 && (size_t)flags.precision > ft_strlen(str))
		flags.precision = ft_strlen(str);
	if (flags.left == 1)
		cum_len += ft_print_strfl(str, flags);
	if (flags.precision >= 0)
		cum_len += ft_pad_width(flags.width, flags.precision, 0);
	else
		cum_len += ft_pad_width(flags.width, ft_strlen(str), 0);
	if (flags.left == 0)
		cum_len += ft_print_strfl(str, flags);
	return (cum_len);
}

int	ft_print_prec(const char *str, int precision)
{
	int	cum_len;

	cum_len = 0;
	while (str[cum_len] && cum_len < precision)
		write(1, &str[cum_len++], 1);
	return (cum_len);
}

int	ft_print_str(const char *str)
{
	int	len;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
	return (len);
}
