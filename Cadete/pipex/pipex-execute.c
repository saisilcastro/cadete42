/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex-execute.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 08:05:05 by mister-code       #+#    #+#             */
/*   Updated: 2023/06/26 08:35:48 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void file_exists(t_pipe  *set);

void    pipe_execute(t_pipe *set)
{
    if (!set)
        return ;
    file_exists(set);
}

static void file_exists(t_pipe  *set)
{
    t_chained   *path;
    t_chained   *cmd;
    t_command   *command;
    char        file[64];
    
    if (!set)
        return ;
    path = set->path;
    while (path)
    {
        cmd = set->cmd;
        while (cmd)
        {
            command = cmd->data;
            sprintf(file, "%s/%s", (char *)path->data, command->name);
            if (access(file, F_OK) == 0)
            {
                printf("executing %s in %s\n", command->name, (char *)path->data);
            }
            cmd = cmd->next;
        }
        path = path->next;
    }
}