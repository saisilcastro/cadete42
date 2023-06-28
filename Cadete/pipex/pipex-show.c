/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex-show.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 23:47:09 by mister-code       #+#    #+#             */
/*   Updated: 2023/06/28 00:01:13 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	pipe_show(t_pipe *set)
{
	t_chained	*flag;

	if (!set)
		return ;
	while (set->path)
	{
		printf("Path: %s\n", (char *)set->path->data);
		set->path = set->path->next;
	}
	while (set->cmd)
	{
		printf("Name: %s", ((t_command *)set->cmd->data)->name);
		flag = ((t_command *)set->cmd->data)->flag;
		while (flag)
		{
			printf(" %s", (char *)flag->data);
			flag = flag->next;
		}
		printf("\n");
		set->cmd = set->cmd->next;
	}
}
