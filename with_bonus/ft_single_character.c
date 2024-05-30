/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_single_character.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:57:05 by anmakaro          #+#    #+#             */
/*   Updated: 2024/05/27 11:34:21 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(char c, t_format flags)
{
	int	count;

	count = 0;
	if (flags.left == 1)
		count += ft_putchar(c);
	count += ft_apply_padding(flags.width, 1, flags.zero);
	if (flags.left == 0)
		count += ft_putchar(c);
	return (count);
}
