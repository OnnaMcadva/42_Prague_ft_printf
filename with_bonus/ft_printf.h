#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>

typedef struct s_format
{
	int	spec;
	int	width;
	int	left;
	int	zero;
	int	star;
	int	precision;
	int	hash;
	int	space;
	int	plus;
}		t_format;

t_format	ft_flags_handle(void);
t_format	ft_flag_left(t_format flags);
t_format	ft_flag_digit(char c, t_format flags);
t_format	ft_flag_width(va_list args, t_format flags);

int	ft_flag_precision(const char *str, int pos, va_list args, t_format *flags);


#endif