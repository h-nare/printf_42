/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narehakobyan <narehakobyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:37:19 by narhakob          #+#    #+#             */
/*   Updated: 2026/03/05 00:11:36 by narehakobya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexadecimal(unsigned long n, char case_type)
{
	char	digit;
	int		count;

	count = 0;
	if (n >= 16)
		count += ft_hexadecimal(n / 16, case_type);

	if ((n % 16) < 10)
		digit = '0' + (n % 16);
	else if (case_type == 'x')
		digit = 'a' + (n % 16 - 10);
	else
		digit = 'A' + (n % 16 - 10);

	count += write(1, &digit, 1);
	return (count);
}

static int	ft_hexadecimal(uintptr_t n, char case_type)
{
	char	digit;
	int		count;

	count = 0;
	if (n >= 16)
		count += ft_hexadecimal(n / 16, case_type);

	if ((n % 16) < 10)
		digit = '0' + (n % 16);
	else if (case_type == 'x')
		digit = 'a' + (n % 16 - 10);
	else
		digit = 'A' + (n % 16 - 10);

	count += write(1, &digit, 1);
	return (count);
}

int	print_pointer(void *ptr)
{
	uintptr_t	address;
	int				count;

	if (!ptr)
		return (write(1, "(nil)", 5));

	address = (uintptr_t)ptr;
	count = 0;
	count += write(1, "0x", 2);
	count += ft_hexadecimal(address, 'x');
	return (count);
}
