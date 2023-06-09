/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:34:54 by lde-cast          #+#    #+#             */
/*   Updated: 2023/03/17 11:26:51 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	current;
	int	factorial;

	if (nb == 0)
		return (1);
	current = 0;
	factorial = 1;
	while (++current <= nb)
		factorial *= current;
	return (factorial);
}
