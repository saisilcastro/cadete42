/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex-file-get.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 23:02:36 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/28 21:52:33 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	input_name_get(t_pipe *set, char **argv);
static void	output_name_get(t_pipe *set, int argc, char **argv);

void	pipe_file_get(t_pipe *set, int argc, char **argv)
{
	if (!set || !argv)
		return ;
	input_name_get(set, argv);
	set->descriptor->input = open(set->input, O_WRONLY, 0777);
	if (set->descriptor->input == -1)
	{
		printf("%s: No such file or directory\n", set->input);
		return ;
	}
	output_name_get(set, argc, argv);
	set->descriptor->output = open(set->output, O_RDONLY | O_CREAT, 0777);
}

static void	input_name_get(t_pipe *set, char **argv)
{
	int	pos;

	if (!set || !argv)
		return ;
	set->input = (char *)malloc(ft_strlen(*(argv + 1)) + 1 * sizeof(char));
	pos = 0;
	while (*(*(argv + 1) + pos))
	{
		*(set->input + pos) = *(*(argv + 1) + pos);
		pos++;
	}
	*(set->input + pos) = '\0';
}

static void	output_name_get(t_pipe *set, int argc, char **argv)
{
	int	pos;
	int	len;

	if (!set || !argv)
		return ;
	len = ft_strlen(*(argv + argc - 1));
	set->output = (char *)malloc(len + 1 * sizeof(char));
	pos = 0;
	while (*(*(argv + argc - 1) + pos))
	{
		*(set->output + pos) = *(*(argv + argc - 1) + pos);
		pos++;
	}
	*(set->output + pos) = '\0';
}
