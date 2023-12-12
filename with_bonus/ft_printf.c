#include "ft_printf.h"

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
