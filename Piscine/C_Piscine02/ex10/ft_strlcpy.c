/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:46:34 by lde-cast          #+#    #+#             */
/*   Updated: 2023/03/21 12:27:52 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	mem;

	if (size <= 0)
		size = 1;
	mem = 0;
	while (*(src + mem) && mem < size - 1)
	{
		*(dest + mem) = *(src + mem);
		mem++;
	}
	*(dest + mem) = '\0';
	while (*(src + mem) != '\0')
		mem++;
	return (mem);
}
