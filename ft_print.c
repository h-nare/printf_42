/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narhakob <narhakob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:37:03 by narhakob          #+#    #+#             */
/*   Updated: 2026/02/27 21:52:19 by narhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return (write(1, "(null)", 6));
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_conversion(va_list var, char format)
{
	int	printed_char;

	printed_char = 0;
	if (format == 'c')
		printed_char = ft_putchar(va_arg(var, int));
	else if (format == 's')
		printed_char = ft_putstr(va_arg(var, char *));
	else if (format == 'd' || format == 'i')
		printed_char = ft_putnbr(va_arg(var, int));
	else if (format == 'u')
		printed_char = ft_unsigned(va_arg(var, unsigned int));
	else if (format == '%')
		printed_char = write(1, "%", 1);
	else if (format == 'x' || format == 'X')
		printed_char = ft_hexidecimal(va_arg(var, unsigned int), format);
	else if (format == 'p')
		printed_char = print_pointer(va_arg(var, void *));
	return (printed_char);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		total;

	total = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			total += ft_conversion(args, *format);
		}
		else
			total += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (total);
}
