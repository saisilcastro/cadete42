/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:44:12 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/29 12:19:21 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(char *str)
{
	char	*buffer;
	int		pos;
	int		len;

	len = ft_strlen(str);
	if (!str || !len)
		return (NULL);
	buffer = (char *)malloc((len + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	pos = 0;
	while (pos < len)
	{
		*(buffer + pos) = *(str + pos);
		pos++;
	}
	*(buffer + pos) = '\0';
	return (buffer);
}
