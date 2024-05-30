/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned_decimal.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 13:16:15 by annavm            #+#    #+#             */
/*   Updated: 2024/05/27 15:14:08 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_uns_int(char *nmbstr, t_format flags)
{
	int	count;

	count = 0;
	if (flags.precision >= 0)
		count += ft_apply_padding(flags.precision - 1,
				ft_strlen(nmbstr) - 1, 1);
	count += ft_print_str(nmbstr);
	return (count);
}

int	ft_format_uns_int(char *nmbstr, t_format flags)
{
	int	count;

	count = 0;
	if (flags.left == 1)
		count += ft_print_uns_int(nmbstr, flags);
	if (flags.precision >= 0 && (size_t)flags.precision < ft_strlen(nmbstr))
		flags.precision = ft_strlen(nmbstr);
	if (flags.precision >= 0)
	{
		flags.width -= flags.precision;
		count += ft_apply_padding(flags.width, 0, 0);
	}
	else
		count += ft_apply_padding(flags.width, ft_strlen(nmbstr), flags.zero);
	if (flags.left == 0)
		count += ft_print_uns_int(nmbstr, flags);
	return (count);
}

int	ft_print_unsigned_decimal(long n, t_format flags)
{
	char	*nmbstr;
	int		cum_len;

	cum_len = 0;
	if (flags.precision == 0 && n == 0)
	{
		cum_len += ft_apply_padding(flags.width, 0, 0);
		return (cum_len);
	}
	nmbstr = ft_itoa_base(n, 10);
	if (!nmbstr)
		return (0);
	cum_len += ft_format_uns_int(nmbstr, flags);
	free(nmbstr);
	return (cum_len);
}
