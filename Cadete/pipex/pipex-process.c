/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex-process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 14:45:30 by mister-code       #+#    #+#             */
/*   Updated: 2023/06/29 00:32:30 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include "pipex.h"
#include "process_of.h"

void	process_start(t_process *set, t_descriptor *descriptor)
{
	int	i;

	if (!set)
		return ;
	i = 0;
	set->descriptor = descriptor;
	set->path = NULL;
	set->flag = NULL;
}

void	process_prepare(t_process *set, t_command *command)
{
	int	max_flag;
	int	current_flag;

	if (!set || !command || !command->flag)
		return ;
	max_flag = chained_max(command->flag);
	set->flag = (char **)malloc(sizeof(char *) * (max_flag + 2));
	if (set->flag)
	{
		*(set->flag + 0) = ft_strdup("none");
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

void	process_pop(t_process *set, int max)
{
	int			i;

	if (!set)
		return ;
	i = 0;
	if (set->flag)
	{
		printf("poping process flag\n");
		while (*(set->flag + i) && i <= max)
		{
			printf("inside process removing %s\n", *(set->flag + i));
			free(*(set->flag + i));
			i++;
		}
		free(set->flag);
	}
}
