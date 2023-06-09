/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 10:54:28 by lde-cast          #+#    #+#             */
/*   Updated: 2023/03/08 12:51:21 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap_buffer(int *a, int *b);

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size)
	{
		while (j < size)
		{
			if (tab[i] > tab[j])
				swap_buffer(&tab[i], &tab[j]);
			j++;
		}
		j = i + 1;
		i++;
	}
}

void	swap_buffer(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}
