/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:39:20 by jkasmirs          #+#    #+#             */
/*   Updated: 2023/03/10 15:00:44 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_function(char p, char s, char t)
{
	ft_putchar(p);
	ft_putchar(s);
	ft_putchar(t);
	if (p == '7' && s == '8' && t == '9')
		write(1, "\n", 1);
	else
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	char	p;
	char	s;
	char	t;

	p = '0';
	while (p <= '7')
	{
		s = p + 1;
		while (s <= '8')
		{
			t = s + 1;
			while (t <= '9')
			{
				ft_function(p, s, t);
				t++;
			}
		s++;
		}
	p++;
	}
}

int	main(void)
{
	ft_print_comb();
	return (0);
}
