/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadecimal.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 15:18:45 by annavm            #+#    #+#             */
/*   Updated: 2024/05/28 22:38:23 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_prefix(int is_up)
{
	if (is_up == 1)
		ft_print_str("0X");
	else
		ft_print_str("0x");
	return (2);
}

int	ft_format_hex(char *nmbstr, int n, int is_up, t_format flags)
{
	int	count;

	count = 0;
	if (flags.zero == 0 && flags.hash == 1 && n != 0)
		count += ft_prefix(is_up);
	if (flags.precision >= 0)
		count += ft_apply_padding(flags.precision - 1,
				ft_strlen(nmbstr) - 1, 1);
	count += ft_print_str(nmbstr);
	return (count);
}

int	ft_print_hex(char *nmbstr, int n, int is_up, t_format flags)
{
	int	count;

	count = 0;
	if (flags.zero == 1 && flags.hash == 1 && n != 0)
		count += ft_prefix(is_up);
	if (flags.left == 1)
		count += ft_format_hex(nmbstr, n, is_up, flags);
	if (flags.precision >= 0 && (size_t)flags.precision < ft_strlen(nmbstr))
		flags.precision = ft_strlen(nmbstr);
	if (flags.precision >= 0)
	{
		flags.width -= flags.precision;
		count += ft_apply_padding(flags.width, 0, 0);
	}
	else
		count += ft_apply_padding(flags.width,
				ft_strlen(nmbstr) + (flags.hash * 2), flags.zero);
	if (flags.left == 0)
		count += ft_format_hex(nmbstr, n, is_up, flags);
	return (count);
}

int	ft_print_hexadecimal(unsigned int n, int is_up, t_format flags)
{
	char	*nmbstr;
	int		count;

	count = 0;
	if (flags.precision == 0 && n == 0)
	{
		count += ft_apply_padding(flags.width, 0, 0);
		return (count);
	}
	nmbstr = ft_itoa_hex(n, is_up);
	if (!nmbstr)
		return (0);
	count += ft_print_hex(nmbstr, n, is_up, flags);
	free(nmbstr);
	return (count);
}
