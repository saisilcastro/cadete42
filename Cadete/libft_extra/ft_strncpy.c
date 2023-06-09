/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:37:10 by lde-cast          #+#    #+#             */
/*   Updated: 2023/04/29 15:12:31 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	pos;

	pos = 0;
	while (*(src + pos) && pos < n)
	{
		*(dest + pos) = *(src + pos);
		pos++;
	}
	*(dest + pos) = '\0';
	return (dest);
}
