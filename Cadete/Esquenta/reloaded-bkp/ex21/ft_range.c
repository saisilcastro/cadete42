/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 11:03:35 by lde-cast          #+#    #+#             */
/*   Updated: 2023/04/21 17:55:11 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

int	*ft_range(int min, int max)
{
	int	*array;
	int	len;
	int	value;
	int	pos;

	len = max - min;
	if (min >= max)
		return (NULL);
	array = malloc(len * sizeof(int));
	value = min;
	pos = 0;
	while (pos < len)
	{
		array[pos] = value;
		value++;
		pos++;
	}
	return (array);
}
