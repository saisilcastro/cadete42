#include <unistd.h>
#include <stdio.h>
#include "ft_itoa_base.h"

void ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_itoa_base(int nb, unsigned char base, unsigned char upper)
{
    char		multiply;
	static int	len;

	multiply = 1;
	len = 1;
	if (nb > -base && nb < 0)
	{
		ft_putchar_fd('-', 1);
		len = 2;
	}
	while (nb <= -base || nb >= base)
	{
		ft_itoa_base((nb / base), base, upper);
		nb %= base;
		len++;
	}
	if (nb < 0)
		multiply = -1;
	if (nb * multiply < 10)
		ft_putchar_fd((nb * multiply) + 48, 1);
	else
	{
		if (!upper)
			ft_putchar_fd((nb * multiply) + 87, 1);
		else
			ft_putchar_fd((nb * multiply) + 55, 1);
	}
    return (len);
}

int	ft_itoa_base_unsigned(unsigned nb, unsigned char base, unsigned char upper)
{
	char		multiply;
	static int	len;

	multiply = 1;
	if ((int)nb > -base && (int)nb < 0)
		ft_putchar_fd('-', 1);
	len = 1;
	while ((int)nb <= -base || nb >= base)
	{
		ft_itoa_base_unsigned((nb / base), base, upper);
		nb %= base;
		len++;
	}
	if ((int)nb < 0)
		multiply = -1;
	if (nb * multiply < 10)
		ft_putchar_fd((nb * multiply) + 48, 1);
	else
	{
		if (!upper)
			ft_putchar_fd((nb * multiply) + 87, 1);
		else
			ft_putchar_fd((nb * multiply) + 55, 1);
	}
	return (len);
}

int	ft_itoa_base_long(unsigned long nb, unsigned char base, unsigned char upper)
{
	char		multiply;
	static int	len;

	multiply = 1;
	if ((long)nb > -base && (long)nb < 0)
		ft_putchar_fd('-', 1);
	len = 1;
	while ((long)nb <= -base || nb >= base)
	{
		ft_itoa_base_long(nb / base, base, upper);
		nb %= base;
		len++;
	}
	if ((long)nb < 0)
		multiply = -1;
	if (nb * multiply < 10)
		ft_putchar_fd((nb * multiply) + 48, 1);
	else
	{
		if (!upper)
			ft_putchar_fd((nb * multiply) + 87, 1);
		else
			ft_putchar_fd((nb * multiply) + 55, 1);
	}
	return (len);
}