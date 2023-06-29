/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process-of.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 12:36:59 by mister-code       #+#    #+#             */
/*   Updated: 2023/06/29 16:49:09 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "process_of.h"

static void	flag_allocate(t_process *set, t_chained *flag, int max);
static void	flag_loop(char **flag, char *buffer);

t_process	*process_push(char *path, t_chained *flag)
{
	t_process	*process;

	process = (t_process *)malloc(sizeof(t_process));
	if (!path || !process)
		return (NULL);
	process->fd[0] = 0;
	process->fd[1] = 0;
	process->path = path;
	flag_allocate(process, flag, chained_max(flag) + 2);
	return (process);
}

static void	flag_allocate(t_process *process, t_chained *flag, int max)
{
	int			i;
	t_chained	*update;

	if (max > 2)
	{
		process->flag = (char **)malloc(max * sizeof(char *));
		if (!process->flag)
			return ;
		*(process->flag + 0) = ft_strdup("none");
		i = 1;
		update = flag;
		while (update)
		{
			flag_loop(&*(process->flag + i), update->data);
			update = update->next;
			i++;
		}
		*(process->flag + i) = NULL;
	}
	else
		process->flag = NULL;
}

static void	flag_loop(char **flag, char *buffer)
{
	int	len;
	int	i;

	if (!buffer)
		return ;
	len = ft_strlen(buffer);
	*flag = (char *)malloc((len + 1) * sizeof(char));
	if (!*flag)
		return ;
	i = 0;
	while (*buffer)
	{
		*(*flag + i) = *buffer;
		buffer++;
		i++;
	}
	*(*flag + i) = '\0';
}

void	process_pop(t_process *set)
{
	int	i;

	if (!set)
		return ;
	if (set->path)
		free(set->path);
	if (set->flag)
	{
		i = 0;
		while (*(set->flag + i))
		{
			free(*(set->flag + i));
			i++;
		}
		free(set->flag);
		set->flag = NULL;
	}
	free(set);
}
