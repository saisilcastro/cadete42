/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:46:36 by lde-cast          #+#    #+#             */
/*   Updated: 2023/04/29 19:58:03 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	size_t	x;
	size_t	y;
	size_t	found;

	x = 0;
	found = 0;
	while (*(big + x))
	{
		y = 0;
		while (*(big + x + y) == *(little + y) && *(big + x + y))
			y++;
		if (!*(little + y))
			return ((char *)big + x);
		x++;
	}
	return (0);
}
