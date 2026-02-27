#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h> 
#include <stdarg.h>
#include <limits.h>

int ft_putnbr(int c);
int ft_putstr(char *str);
int ft_putchar(char c);
int ft_unsigned(int c);
int ft_hexidecimal(unsigned int n, char case_type);
int print_pointer(void *ptr);


#endif

