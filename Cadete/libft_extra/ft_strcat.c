/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:37:41 by lde-cast          #+#    #+#             */
/*   Updated: 2023/04/29 15:13:33 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	size_t	offset;
	size_t	pos;

	offset = 0;
	while (*(dest + offset))
		offset++;
	pos = 0;
	while (*(src + pos))
	{
		*(dest + offset + pos) = *(src + pos);
		pos++;
	}
	return (dest);
}
