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

static unsigned int	ft_number_size(long nbr)
{
	unsigned int	digits;

	digits = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		digits += 1;
	while (nbr != 0)
	{
		nbr /= 10;
		digits++;
	}
	return (digits);
}

static char	*ft_itoa(long nbr, char *str, size_t digits)
{
	str = ft_calloc(digits + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = -nbr;
	}
	digits--;
	while (digits)
	{
		str[digits] = (nbr % 10) + '0';
		nbr /= 10;
		digits--;
	}
	if (str[0] != '-')
		str[0] = (nbr % 10) + '0';
	return (str);
}

char	*ft_itoa_v(long nbr)
{
	size_t	digits;
	char	*str;

	digits = ft_number_size(nbr);
	str = 0;
	str = ft_itoa(nbr, str, digits);
	if (!str)
		return (NULL);
	return (str);
}
