/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: narehakobyan <narehakobyan@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/26 17:42:51 by narehakobya       #+#    #+#             */
/*   Updated: 2026/02/26 20:29:42 by narehakobya      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_hexidecimal(unsigned int n, char case_type)
{
    char digit;
    int count = 0;

    if (n >= 16)
        count += ft_hexidecimal(n / 16, case_type);

    if (n % 16 < 10)
        digit = '0' + (n % 16);
    else
    {
        if (case_type == 'x')       
            digit = 'a' + ((n % 16) - 10);
        else                          
            digit = 'A' + ((n % 16) - 10);
    }

    count += write(1, &digit, 1);
    return count;
}

int print_pointer(void *ptr)
{
    int count;
    unsigned long address = (unsigned long)ptr;
    count = 0;
    count += write(1,"0x",2);
    if(address == 0)
        write(1, "0", 1);
    else
        count += ft_hexidecimal(address,'x');
    return count;
}