/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 13:01:38 by jkasmirs          #+#    #+#             */
/*   Updated: 2023/03/10 15:02:47 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_tab(int e, int f)
{
	char	a;
	char	b;
	char	c;
	char	d;

	a = e / 10 + '0';
	b = e % 10 + '0';
	c = f / 10 + '0';
	d = f % 10 + '0';
	write(1, &a, 1);
	write(1, &b, 1);
	write(1, " ", 1);
	write(1, &c, 1);
	write(1, &d, 1);
	if (e < 98)
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	e;
	int	f;

	e = 0;
	while (e <= 98)
	{
		f = e + 1;
		while (f <= 99)
		{
			ft_tab(e, f);
			f++;
		}
		e++;
	}
}

int	main(void)
{
	ft_print_comb2();
	return (0);
}
