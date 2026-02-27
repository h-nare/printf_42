/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narehakobyan <narehakobyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 18:09:43 by narehakobya       #+#    #+#             */
/*   Updated: 2026/02/26 20:40:21 by narehakobya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_unsigned(int c)
{
	long	nb;
    int count;
    char digit;

	nb = c;
    count = 0;
	if (nb >= 10)
	{
		count += ft_putnbr(nb / 10);   
	}
	else
    {
        digit = ft_putnbr(nb % 10) + '0';
        count += write(1, &digit, 1);
    } 
    return (count);  
}