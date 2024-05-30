/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:56:52 by anmakaro          #+#    #+#             */
/*   Updated: 2024/05/27 12:13:10 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_handle(char *str, va_list args)
{
	int			i;
	int			j;
	int			count;
	t_format	flags;

	i = -1;
	count = 0;
	while (str[++i])
	{
		flags = ft_flags_handle();
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			j = ft_init_flags(str, i, args, &flags);
			if (flags.spec > 0)
				i = j;
			if (str[i] != '\0' && flags.spec > 0 && ft_isspec(str[i]))
				count += ft_init_format(str[i], args, flags);
			else if (str[i] != '\0')
				count += ft_putchar(str[i]);
		}
		else
			count += ft_putchar(str[i]);
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			cum_len;
	char		*dest;

	if (!str || *str == '\0')
		return (0);
	dest = ft_strdup(str);
	if (!dest || *dest == '\0')
		return (0);
	cum_len = 0;
	va_start(args, str);
	cum_len = ft_handle(dest, args);
	va_end(args);
	free(dest);
	return (cum_len);
}
