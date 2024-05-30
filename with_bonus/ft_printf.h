/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:56:57 by anmakaro          #+#    #+#             */
/*   Updated: 2024/05/28 22:37:13 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <limits.h>
# include "libft/libft.h"

# define PTRNULL "(nil)"

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

/*   ft_common            :+:      :+:    :+:   */
int			ft_apply_padding(int total_width, int size, int zero);
int			ft_unsigned_numlen(unsigned long num, int base);

/*   ft_decimal_integer    :+:      :+:    :+:   */
int			ft_fap_nbr(char *nmbstr, int n, t_format flags);
int			ft_print_sign(int n, t_format *flags);
int			ft_format_and_print(char *nmbstr, int n, t_format flags);
int			ft_print_decimal_integer(int n, t_format flags);

/*   ft_flags_handle      :+:      :+:    :+:   */
t_format	ft_flags_handle(void);
t_format	ft_flag_left(t_format flags);
t_format	ft_flag_digit(char c, t_format flags);
t_format	ft_flag_width(va_list args, t_format flags);

int			ft_flag_precision(const char *str, int pos,
				va_list args, t_format *flags);

/*   ft_init              :+:      :+:    :+:   */
int			ft_init_format(char format, va_list args, t_format flags);
int			ft_init_flags(const char *str, int i, va_list args,
				t_format *flags);

/*   ft_print_hexadecimal :+:      :+:    :+:   */
int			ft_prefix(int is_up);
int			ft_format_hex(char *nmbstr, int n, int is_up, t_format flags);
int			ft_print_hex(char *nmbstr, int n, int is_up, t_format flags);
int			ft_print_hexadecimal(unsigned int n, int is_up, t_format flags);

/*   ft_print_pointer     :+:      :+:    :+:   */
void		ft_putptr(unsigned long int num);
int			ft_display_pointer(unsigned long int ptr);
int			ft_print_pointer(unsigned long int ptr, t_format flags);

/*   ft_print_unsigned_decimal :+:      :+:    :+:   */
int			ft_print_uns_int(char *nmbstr, t_format flags);
int			ft_format_uns_int(char *nmbstr, t_format flags);
int			ft_print_unsigned_decimal(long n, t_format flags);

/*   ft_printf            :+:      :+:    :+:   */
int			ft_handle(char *str, va_list args);
int			ft_printf(const char *str, ...);

/*   ft_single_character   :+:      :+:    :+:   */
int			ft_print_char(char c, t_format flags);

/*   ft_string             :+:      :+:    :+:   */
int			ft_print_string(const char *str, t_format flags);
int			ft_print_prec(const char *str, int precision);
int			ft_print_str(const char *str);

/*   ft_what_the_flag      :+:      :+:    :+:   */
int			ft_isflag(int c);
int			ft_ismodi(int c);
int			ft_isspec(int c);

#endif
