/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_common.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:56:33 by anmakaro          #+#    #+#             */
/*   Updated: 2024/05/27 11:34:21 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned_numlen(unsigned long num, int base)
{
	int	len;

	if (base < 2 || base > 16)
		return (0);
	len = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num = num / base;
		len++;
	}
	return (len);
}

int	ft_apply_padding(int total_width, int size, int zero)
{
	int	count;

	count = 0;
	while (total_width - size > 0)
	{
		if (zero)
			count += ft_putchar('0');
		else
			count += ft_putchar(' ');
		total_width--;
	}
	return (count);
}
