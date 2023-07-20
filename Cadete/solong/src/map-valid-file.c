/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-valid-file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 21:00:08 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/19 22:25:16 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map_of.h>

static B32	ft_strlen(B8 *str)
{
	B32	len;

	if (!str)
		return (0);
	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

t_status	map_valid_file(char *path)
{
	B32		len;
	char	*buffer;

	len = ft_strlen(path);
	if (!path || len < 5)
		return (Off);
	buffer = path + len - 4;
	if (*(buffer + 0) == '.' && *(buffer + 1) == 'b'
		&& *(buffer + 2) == 'e' && *(buffer + 3) == 'r')
		return (On);
	return (Off);
}
