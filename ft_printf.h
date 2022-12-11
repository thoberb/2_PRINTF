/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:31:52 by blandineber       #+#    #+#             */
/*   Updated: 2022/12/06 15:14:42 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <unistd.h>
# include <ctype.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>

int					ft_printf(const char *format, ...);
int					ft_printf_arg(const char *fmt, int i, va_list ap);
int					ft_putstr(char *str);
int					ft_putchar(char c);
int					putnbr_u(unsigned int nbr);
int					ft_putnbr(int nbr);
int					put_hex(unsigned int x, char *base);
int					ft_ptr_len(uintptr_t num);
int					ft_print_ptr(unsigned long long ptr);
size_t				ft_strlen(const char *s);
void				ft_put_ptr(uintptr_t num);
char				*ft_strchr(const char *s, int c);
char				*ft_itoa(int n);
char				*ft_utoa(unsigned int n);
unsigned int		get_nb_digit(long n_l, int sign);
void				convert_nb(char *outstr, long n_l, \
								unsigned int nb_digit, int sign);

#endif
