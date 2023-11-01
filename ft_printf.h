#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

void	ft_putchar(char c);
char	*ft_itoa(int n);
int	ft_print_decimal_integer(int n);
int	ft_hexlen(unsigned	int num);
void	ft_puthex(unsigned int num, const char format);
int	ft_print_hexadecimal(unsigned int num, const char format);
int	ft_init_format(va_list args, const char format);
int	ft_print_percent_sign(void);
int	ft_ptrlen(uintptr_t num);
void	ft_putptr(uintptr_t num);
int	ft_print_pointer(unsigned long long ptr);
int	ft_printf(const char *str, ...);
int	ft_print_char(int c);
void	ft_putstr(char *str);
int	ft_print_string(char *str);
int	ft_numlen(unsigned	int num);
char	*ft_uitoa(unsigned int n);
int	ft_print_unsigned_decimal(unsigned int n);
int main();
void test_function();

#endif