/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_v.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakaro <anmakaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:56:09 by anmakaro          #+#    #+#             */
/*   Updated: 2023/12/13 12:56:10 by anmakaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_number_size(long num)
{
	size_t	digits;

	digits = 0;
	if (num == 0)
		return (1);
	if (num < 0)
	{
		digits++;
		num = -num;
	}
	while (num >= 1)
	{
		digits++;
		num /= 10;
	}
	return (digits);
}

static char	*ft_itoa(long num, char *str, size_t digits)
{
	str = ft_calloc(digits + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	digits--;
	while (digits)
	{
		str[digits] = (num % 10) + '0';
		num /= 10;
		digits--;
	}
	if (str[0] != '-')
		str[0] = (num % 10) + '0';
	return (str);
}

char	*ft_itoa_v(long num)
{
	size_t	digits;
	char	*str;

	digits = ft_number_size(num);
	str = 0;
	str = ft_itoa(num, str, digits);
	if (!str)
		return (NULL);
	return (str);
}
