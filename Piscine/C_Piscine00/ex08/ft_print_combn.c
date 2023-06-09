/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 13:33:06 by lde-cast          #+#    #+#             */
/*   Updated: 2023/03/18 15:30:29 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	array_start(int number[10]);
void	swap(int *a, int *b);

void	ft_print_combn(int n)
{
	int	number[10];
	int	i;

	i = 0;
	array_start(number);
	while (n >= 0 && n < 10 && i < n)
	{
		i++;
	}
}

void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	array_start(int number[10])
{
	int	i;

	i = 0;
	while (i < 10)
	{
		number[i] = 0;
		i++;
	}
}
