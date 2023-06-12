#ifndef FT_ITOA_BASE_H
#define FT_ITOA_BASE_H

extern void ft_putchar_fd(char c, int fd);
extern int	ft_itoa_base(int nb, unsigned char base, unsigned char upper);
extern int	ft_itoa_base_unsigned(unsigned nb, unsigned char base, unsigned char upper);
extern int	ft_itoa_base_long(unsigned long nb, unsigned char base, unsigned char upper);

#endif // FT_ITOA_BASE_H