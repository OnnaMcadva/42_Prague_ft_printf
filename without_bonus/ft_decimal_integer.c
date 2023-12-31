/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decimal_integer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anmakaro <anmakaro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 12:11:12 by anmakaro          #+#    #+#             */
/*   Updated: 2023/11/02 12:11:13 by anmakaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static unsigned int	ft_number_size(int number)
{
	unsigned int	digits;

	digits = 0;
	if (number == 0)
		return (1);
	if (number < 0)
		digits += 1;
	while (number != 0)
	{
		number /= 10;
		digits++;
	}
	return (digits);
}

char	*ft_itoa(int n)
{
	unsigned int	number;
	unsigned int	digits;
	char			*string;

	digits = ft_number_size(n);
	string = (char *)malloc(sizeof(char) * (digits + 1));
	if (string == NULL)
		return (NULL);
	if (n < 0)
	{
		string[0] = '-';
		number = -n;
	}
	else
		number = n;
	if (number == 0)
		string[0] = '0';
	string[digits] = '\0';
	while (number != 0)
	{
		string[digits - 1] = (number % 10) + '0';
		number /= 10;
		digits--;
	}
	return (string);
}

int	ft_print_decimal_integer(int n)
{
	int		len;
	char	*num;

	len = 0;
	num = ft_itoa(n);
	len = ft_print_string(num);
	free(num);
	return (len);
}
