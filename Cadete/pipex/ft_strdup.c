/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 22:44:12 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/28 00:12:32 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strdup(char *str)
{
	char	*buffer;
	int		pos;

	if (!str)
		return (NULL);
	buffer = (char *)malloc(ft_strlen(str) + 1 * sizeof(char));
	if (!buffer)
		return (NULL);
	pos = 0;
	while (*(str + pos))
	{
		*(buffer + pos) = *(str + pos);
		pos++;
	}
	*(buffer + pos) = '\0';
	return (buffer);
}