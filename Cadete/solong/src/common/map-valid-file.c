/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map-valid-file.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 21:00:08 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/20 09:24:49 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map_of.h>

static int	ft_strlen(char *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

t_status	map_valid_file(char *path)
{
	int		len;
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
