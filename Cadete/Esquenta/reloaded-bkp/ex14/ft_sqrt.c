/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:59:24 by lde-cast          #+#    #+#             */
/*   Updated: 2023/04/22 11:35:14 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int	current;

	current = 1;
	while (current && current <= 46340)
	{
		if (current * current == nb)
			return (current);
		current++;
	}
	return (0);
}
