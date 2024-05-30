/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: annavm <annavm@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 12:56:23 by anmakaro          #+#    #+#             */
/*   Updated: 2024/05/28 14:28:36 by annavm           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

void	*ft_calloc(size_t count, size_t size);
int		ft_isdigit(int symba);
int		ft_numlen(long num, int base);
char	*ft_itoa_base(long n, int base);
char	*ft_itoa_hex(unsigned long int num, int is_up);
int		ft_putchar(char c);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *str);

#endif
