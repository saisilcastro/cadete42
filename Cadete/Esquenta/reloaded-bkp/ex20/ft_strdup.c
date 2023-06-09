/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 10:47:38 by lde-cast          #+#    #+#             */
/*   Updated: 2023/04/18 11:02:27 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <malloc.h>

int	ft_strlen(char *str);

char	*ft_strdup(char *src)
{
	int		len;
	char	*dst;
	char	*update;

	len = ft_strlen(src);
	dst = malloc(len + 1 * sizeof(char));
	update = dst;
	while (*src)
	{
		*update = *src;
		src++;
		update++;
	}
	*update = '\0';
	return (dst);
}

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len++;
		str++;
	}
	return (len);
}
