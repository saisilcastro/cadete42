/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:03:50 by lde-cast          #+#    #+#             */
/*   Updated: 2023/04/29 15:12:23 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*buffer;

	buffer = (char *)malloc((size + 1) * sizeof(char));
	if (buffer)
	{
		ft_memset(buffer, '\0', size);
		return (buffer);
	}
	return (NULL);
}
