/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msilva-e <msilva-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 19:59:13 by msilva-e          #+#    #+#             */
/*   Updated: 2023/03/18 16:34:05 by msilva-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	while (tab[size])
	{
		write (1, &tab[size], 1);
		size--;
	}
}

int	main(void)
{
	int	array[] = {1, 2, 3, 4, 5};

	ft_rev_int_tab(array, 9);
}
