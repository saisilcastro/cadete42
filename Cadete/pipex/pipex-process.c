/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex-process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 14:45:30 by mister-code       #+#    #+#             */
/*   Updated: 2023/06/27 22:49:12 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include "pipex.h"
#include "process_of.h"

void	process_start(t_process *set, t_descriptor *descriptor)
{
	if (!set)
		return ;
	set->descriptor = descriptor;
	set->path = NULL;
	set->flag = NULL;
}

void	process_prepare(t_process *set, t_command *command)
{
	int	max_flag;
	int	current_flag;

	if (!set || !command)
		return ;
	max_flag = chained_max(command->flag);
	set->flag = (char **)malloc((max_flag + 2) * sizeof(char *));
	if (set->flag)
	{
		*(set->flag + 0) = "none";
		current_flag = 1;
		while (command->flag)
		{
			*(set->flag + current_flag) = ft_strdup(command->flag->data);
			command->flag = command->flag->next;
			current_flag++;
		}
		*(set->flag + current_flag) = NULL;
	}
}

void	process_pop(t_process *set)
{
	int		i;

	if (!set)
		return ;
	if (set->flag)
	{
		i = 1;
		while (set->flag && *(set->flag + i))
		{
			free(*(set->flag + i));
			i++;
		}
		free(set->flag);
	}
}
