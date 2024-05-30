/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/27 14:35:18 by annavm            #+#    #+#             */
/*   Updated: 2024/05/27 15:00:35 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	ft_get_base(int b)
{
	char	*base;

	base = "0123456789ABCDEF";
	return (base[b]);
}

int	ft_numlen(long num, int base)
{
	int	len;

	if (base < 2 || base > 16)
		return (0);
	len = 0;
	if (num < 0)
	{
		num = -num;
		len++;
	}
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num = num / base;
		len++;
	}
	return (len);
}

static void	ft_fill_res(int start_index, long n, char *res, int base)
{
	int	size;

	size = ft_numlen(n, base);
	while (size > start_index)
	{
		res[size - 1] = ft_get_base(n % base);
		n = n / base;
		size--;
	}
}

char	*ft_itoa_base(long n, int base)
{
	int				start_index;
	int				size;
	unsigned int	num;
	char			*res;

	if (base < 2 || base > 16)
		return (NULL);
	if (n == INT_MIN && base == 10)
		return ("-2147483648");
	size = ft_numlen(n, base);
	res = (char *)malloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	start_index = 0;
	if (n < 0)
	{
		res[0] = '-';
		start_index = 1;
		num = -n;
	}
	else
		num = n;
	ft_fill_res(start_index, num, res, base);
	res[size] = '\0';
	return (res);
}
