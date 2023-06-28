/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 10:25:13 by mister-code       #+#    #+#             */
/*   Updated: 2023/06/27 23:42:13 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	path_create(char *fpath, char *path, char *app)
{
	int	pos;
	int	i;

	if (!fpath || !path || !app)
		return ;
	i = 0;
	pos = 0;
	while (*(path + i))
	{
		*(fpath + pos) = *(path + i);
		i++;
		pos++;
	}
	*(fpath + pos) = '/';
	pos++;
	i = 0;
	while (*(app + i))
	{
		*(fpath + pos) = *(app + i);
		i++;
		pos++;
	}
	*(fpath + pos) = '\0';
}
