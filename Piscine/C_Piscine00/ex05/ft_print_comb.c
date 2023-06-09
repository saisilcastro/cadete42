/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 10:51:14 by lde-cast          #+#    #+#             */
/*   Updated: 2023/03/17 18:32:38 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	ft_print_comb(void);
void	print_sequence(char *comb);

void	ft_print_comb(void)
{
	char	comb[3];

	comb[0] = 48;
	while (comb[0] <= 55)
	{
		comb[1] = comb[0] + 1;
		while (comb[1] <= 56)
		{
			comb[2] = comb[1] + 1;
			while (comb[2] <= 57)
			{
				print_sequence(comb);
				comb[2]++;
			}
			comb[1]++;
		}
		comb[0]++;
	}
}

void	print_sequence(char comb[3])
{
	write(1, &comb[0], 1);
	write(1, &comb[1], 1);
	write(1, &comb[2], 1);
	if (comb[0] != '7' || comb[1] != '8' || comb[2] != '9')
		write(1, ", ", 2);
}
