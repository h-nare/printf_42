/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narhakob <narhakob@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/27 17:37:38 by narhakob          #+#    #+#             */
/*   Updated: 2026/02/27 17:43:58 by narhakob         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_unsigned(unsigned int n)
{
	int		count;
	char	digit;

	count = 0;
	if (n >= 10)
		count += ft_unsigned(n / 10);
	digit = (n % 10) + '0';
	count += write(1, &digit, 1);
	return (count);
}
