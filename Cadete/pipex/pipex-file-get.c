/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex-file-get.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 23:02:36 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/25 15:01:48 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_strlen(char *str)
{
	int len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}

void	pipe_file_get(t_pipe *set, int argc, char **argv)
{
	int	pos;

	if (argc < 5 || !set)
		return ;
	set->input = (char *)malloc(ft_strlen(*(argv + 1)) + 1 * sizeof(char));
	pos = 0;
	while (*(*(argv + 1) + pos))
	{
		*(set->input + pos) = *(*(argv + 1) + pos);
		pos++;	
	}
	*(set->input + pos) = '\0';
	set->output = (char *)malloc(ft_strlen(*(argv + argc - 1)) + 1 * sizeof(char));
	pos = 0;
	while (*(*(argv + argc - 1) + pos))
	{
		*(set->output + pos) = *(*(argv + argc - 1) + pos);
		pos++;
	}
	*(set->output + pos) = '\0';
}
