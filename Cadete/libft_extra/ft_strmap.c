/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:09:49 by lde-cast          #+#    #+#             */
/*   Updated: 2023/04/29 20:36:53 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		len;
	int		i;
	char	*buffer;

	len = ft_strlen(s);
	buffer = (char *)malloc(len + 1 * sizeof(char));
	i = 0;
	buffer = (char *)s;
	while (*(s + i))
	{
		*(buffer + i) = f(*(s + i));
		i++;
	}
	*(buffer + 1) = '\0';
	return (buffer);
}
