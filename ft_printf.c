/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bberthod <bberthod@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 15:34:18 by blandineber       #+#    #+#             */
/*   Updated: 2022/12/06 14:56:41 by bberthod         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_arg(const char *fmt, int i, va_list ap)
{
	if (fmt[i + 1] == '%')
		return (ft_putchar(fmt[i + 1]));
	else if (fmt[i + 1] == 'c')
		return (ft_putchar(va_arg(ap, int)));
	else if (fmt[i + 1] == 's')
		return (ft_putstr(va_arg(ap, char *)));
	else if (fmt[i + 1] == 'd' || fmt[i + 1] == 'i')
		return (ft_putnbr(va_arg(ap, int)));
	else if (fmt[i + 1] == 'u')
		return (putnbr_u(va_arg(ap, unsigned int)));
	else if (fmt[i + 1] == 'x' || fmt[i + 1] == 'X')
	{
		if (fmt[i + 1] == 'X')
			return (put_hex(va_arg(ap, unsigned int), "0123456789ABCDEF"));
		else
			return (put_hex(va_arg(ap, unsigned int), "0123456789abcdef"));
	}
	else if (fmt[i + 1] == 'p')
		return (ft_print_ptr(va_arg(ap, unsigned long long)));
	else
		return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		ret;

	i = 0;
	ret = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%' && ft_strchr("cspdiuxX%", format[i + 1]))
		{
			ret += ft_printf_arg(format, i, ap);
			i++;
		}
		else
			ret += ft_putchar(format[i]);
		i++;
	}
	va_end(ap);
	return (ret);
}

/*
int	main(void)
{
	int res = ft_printf("Integers: %p \n", 66654);
	int res2 = printf("Integers: %p \n", 66654);

	printf("\nres = %d\nres2 = %d\n", res, res2);
}

	printf ("Integers: %i %u \n", -3456, 3456);
	printf ("Characters: %c %c \n", 'z', 80);
	printf ("Decimals: %d %ld\n", 1997, 32000L);
	printf ("Some different radices: %d %x %o %#x %#o \n", 100, 100, 100, 100, 100);
	printf ("floats: %4.2f %+.0e %E \n", 3.14159, 3.14159, 3.14159);
	printf ("Preceding with empty spaces: %10d \n", 1997);
	printf ("Preceding with zeros: %010d \n", 1997);
	printf ("Width: %*d \n", 15, 140);
	printf ("%s \n", "Educative");
*/
