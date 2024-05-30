/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 21:40:10 by annavm            #+#    #+#             */
/*   Updated: 2024/05/28 22:39:03 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr(unsigned long int num)
{
	if (num >= 16)
	{
		ft_putptr(num / 16);
		ft_putptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar(num + '0');
		else
			ft_putchar(num - 10 + 'a');
	}
}

int	ft_display_pointer(unsigned long int ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
	{
		count += ft_print_str(PTRNULL);
		return (count);
	}
	count += ft_print_str("0x");
	ft_putptr(ptr);
	count += ft_unsigned_numlen(ptr, 16);
	return (count);
}

int	ft_print_pointer(unsigned long int ptr, t_format flags)
{
	int	cum_len;
	int	ptr_len;

	cum_len = 0;
	if (ptr == 0)
		ptr_len = ft_strlen(PTRNULL);
	else
		ptr_len = ft_unsigned_numlen(ptr, 16) + 2;
	if (flags.left == 1)
		cum_len += ft_display_pointer(ptr);
	cum_len += ft_apply_padding(flags.width, ptr_len, 0);
	if (flags.left == 0)
		cum_len += ft_display_pointer(ptr);
	return (cum_len);
}
