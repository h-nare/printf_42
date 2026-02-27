/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narhakob <narhakob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:37:19 by narhakob          #+#    #+#             */
/*   Updated: 2026/02/27 21:52:05 by narhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexidecimal(unsigned int n, char case_type)
{
	char	digit;
	int		count;

	count = 0;
	if (n >= 16)
		count += ft_hexidecimal(n / 16, case_type);
	if ((n % 16) < 10)
		digit = '0' + (n % 16);
	else
	{
		if (case_type == 'x')
			digit = 'a' + ((n % 16) - 10);
		else
			digit = 'A' + ((n % 16) - 10);
	}
	count += write(1, &digit, 1);
	return (count);
}

int	print_pointer(void *ptr)
{
	long long	address;
	int			count;

	if (!ptr)
		return (write(1, "(nil)", 5));
	address = (long long)ptr;
	count = 0;
	count += write(1, "0x", 2);
	if (address == 0)
		count += write(1, "0", 1);
	else
		count += ft_hexidecimal(address, 'x');
	return (count);
}

