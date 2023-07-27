#include <stdio.h>
#include "ft_printf.h"
int main() {
    int a = 42;
    char *str = "Hello, world!";
    unsigned int b = 12345;
    unsigned long long c = 0xABCD1234;

    // Test ft_printf function
    ft_printf("Test int: %d\n", a);
    ft_printf("Test string: %s\n", str);
    ft_printf("Test unsigned int: %u\n", b);
    ft_printf("Test hexadecimal: %X\n", c);
    ft_printf("Test pointer: %p\n", &a);
    printf("\np = %p", &a);
    return 0;
}
