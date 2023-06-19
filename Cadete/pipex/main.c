/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 10:55:56 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/18 21:15:16 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include <stdio.h>

int	main(int argc, char **argv, char **envp)
{
	while (*envp)
	{
		printf("%s\n", *envp++);
	}
	return (0);
}

void	backup(void)
{
	t_pipex		pipex;
	t_chained	*cmd;

	pipex_start(&pipex);
	cmd = pipex.cmd;
	while (cmd)
	{
		if (cmd->data)
			printf("%s\n", (char *)cmd->data);
		cmd = cmd->next;
	}
	chained_delete(&pipex.cmd);
}
