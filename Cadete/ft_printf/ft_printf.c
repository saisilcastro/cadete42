#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_printf.h"

void	ft_print_special(const char *buffer, va_list list, int *len, int pos)
{
	if (*(buffer + pos) == 'b')
		*len += ft_itoa_base(va_arg(list, int), 2, 0) - 1;
	if (*(buffer + pos) == 'o')
		*len += ft_itoa_base_unsigned(va_arg(list, int), 8, 0) - 1;
	if (*(buffer + pos) == 'd' || *(buffer + pos) == 'i')
		*len += ft_itoa_base(va_arg(list, int), 10, 1) - 1;
	if (*(buffer + pos) == 'u')
		*len += ft_itoa_base_unsigned(va_arg(list, unsigned int), 10, 0) - 1;
	if (*(buffer + pos) == 'x')
		*len += ft_itoa_base_unsigned(va_arg(list, int), 16, 0) - 1;
	if (*(buffer + pos) == 'X')
		*len += ft_itoa_base_unsigned(va_arg(list, int), 16, 1) - 1;
	if (*(buffer + pos) == 'p')
		*len += write(1, "0x", 2) + ft_itoa_base_long(va_arg(list, unsigned long), 16, 0) - 1;
	if (*(buffer + pos) == '%')
		*len += write(1, "%", 1) - 1;
}

int	ft_printf(const char *str, ...)
{
	int		pos;
	int		len;
	va_list	list;

	va_start(list, str);
	pos = -1;
	len = 0;
	while (*(str + ++pos))
	{
		if (*(str + pos) == '%')
		{
			pos++;
			len--;
			ft_print_special(str, list,  &len, pos);
		}
		else
			ft_putchar_fd(*(str + pos), 1);
	}
	va_end(list);
	return (pos + len);
}