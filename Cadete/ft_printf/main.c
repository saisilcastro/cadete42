#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int l1, l2;
    l1 = ft_printf("hello world %p \n", (void *)-32000);
    l2 = printf("hello world %p \n", (void *)-32000);
    printf("%i %i", l1, l2);
    return (0);
}