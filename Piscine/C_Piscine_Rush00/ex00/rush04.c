/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 20:57:58 by lde-cast          #+#    #+#             */
/*   Updated: 2023/03/06 12:09:36 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	rush(int x, int y);
void	top(int x_current, int x_end);
void	middle(int x_current, int x_end);
void	bottom(int x_current, int x_end);

void	rush(int x, int y)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < y && x > 0)
	{
		while (i < x)
		{
			if (j == 0)
				top(i, x - 1);
			else if (j < y - 1)
				middle(i, x - 1);
			else
				bottom(i, x - 1);
			i++;
		}
		ft_putchar('\n');
		j++;
		i = 0;
	}
}

void	top(int x_current, int x_end)
{
	if (x_current == 0)
		ft_putchar('A');
	else if (x_current < x_end)
		ft_putchar('B');
	else
		ft_putchar('C');
}

void	middle(int x_current, int x_end)
{
	if (x_current == 0 || x_current == x_end)
		ft_putchar('B');
	else
		ft_putchar(' ');
}

void	bottom(int x_current, int x_end)
{
	if (x_current == 0)
		ft_putchar('C');
	else if (x_current < x_end)
		ft_putchar('B');
	else
		ft_putchar('A');
}
