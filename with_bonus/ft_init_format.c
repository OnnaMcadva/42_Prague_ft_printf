#include "ft_printf.h"

int	ft_init_format(char format, va_list args, t_format flags)
{
	int	cum_len;

	cum_len = 0;
	if (format == 'c')
		cum_len
			+= ft_print_char(va_arg(args, int), flags);
	else if (format == 's')
		cum_len
			+= ft_print_string(va_arg(args, const char *), flags);
	else if (format == 'p')
		cum_len
			+= ft_print_pointer((unsigned long int)va_arg(args, void *), flags);
	else if (format == 'd' || format == 'i')
		cum_len
			+= ft_print_decimal_integer(va_arg(args, int), flags);
	else if (format == 'u')
		cum_len
			+= ft_print_unsigned_decimal(va_arg(args, unsigned int), flags);
	else if (format == 'x' || format == 'X')
		cum_len
			+= ft_print_hexadecimal(va_arg(args, unsigned int), flags);
	else if (format == '%')
		cum_len
			+= ft_print_char('%', flags);
	return (cum_len);
}

int	ft_init_flags(const char *str, int i, va_list args, t_format *flags)
{
	while (str[++i] && ft_isflag(str[i]))
	{
		if (str[i] == '-')
			*flags = ft_flag_left(*flags);
		if (str[i] == '#')
			flags->hash = 1;
		if (str[i] == ' ')
			flags->space = 1;
		if (str[i] == '+')
			flags->plus = 1;
		if (str[i] == '0' && flags->left == 0 && flags->width == 0)
			flags->zero = 1;
		if (str[i] == '.')
			i = ft_flag_precision(str, i, args, flags);
		if (str[i] == '*')
			*flags = ft_flag_width(args, *flags);
		if (ft_isdigit(str[i]))
			*flags = ft_flag_digit(str[i], *flags);
		if (ft_ismodi(str[i]))
		{
			flags->spec = str[i];
			break ;
		}
	}
	return (i);
}

int	ft_handle(char *str, va_list args)
{
	int		i;
	int		j;
	int		count;
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
			if (str[i] != '\0' && flags.spec > 0 && ft_ismodi(str[i]))
				count += ft_init_format(str[i], args, flags);
			else if (str[i] != '\0')
				count += ft_print_c(str[i]);
		}
		else
			count += ft_print_c(str[i]);
	}
	return (count);
}