/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:33:18 by lde-cast          #+#    #+#             */
/*   Updated: 2023/04/29 15:14:28 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, void *src, int c, size_t n)
{
	size_t	pos;
	size_t	len;
	char	*s;
	char	*d;

	pos = 0;
	len = 0;
	s = src;
	d = dest;
	while (*(s + pos) && pos < n)
	{
		*(d + pos) = *(s + pos);
		if (*(s + pos) == c)
		{
			pos++;
			break ;
		}
		pos++;
		len++;
	}
	if (*(s + pos - 1) && *(d + pos - 1) != c)
		return (NULL);
	*(d + pos) = '\0';
	return (d);
}
