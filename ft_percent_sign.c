#include "ft_printf.h"

int	ft_print_percent_sign(void)
{
	write(1, "%", 1);
	return (1);
}