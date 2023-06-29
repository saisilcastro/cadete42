/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex-environment-get.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 04:17:59 by mister-code       #+#    #+#             */
/*   Updated: 2023/06/28 23:03:50 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_strsub(char *str, char *sub);
static void	path_split(t_pipe *set, char *str);

void	pipe_environment_get(t_pipe *set, char **envp)
{
	char	*buffer;

	if (!set || !*envp)
		return ;
	while (*envp)
	{
		buffer = ft_strsub(*envp, "PATH=");
		if (buffer)
			path_split(set, buffer + 5);
		envp++;
	}
}

static void	path_split(t_pipe *set, char *str)
{
	char	buffer[1024];
	int		i;

	if (!set || !str)
		return ;
	i = 0;
	while (*str)
	{
		*(buffer + i) = *str;
		if (*str == ':')
		{
			*(buffer + i) = '\0';
			chained_next_last(&set->path, chained_push(ft_strdup(buffer)));
			i = -1;
		}
		str++;
		i++;
	}
	if (i)
	{
		*(buffer + i) = '\0';
		chained_next_last(&set->path, chained_push(ft_strdup(buffer)));
	}
}

static char	*ft_strsub(char *str, char *sub)
{
	char	*start;
	char	*loop;

	if (!str)
		return (NULL);
	while (*str)
	{
		if (*str == *sub)
		{
			start = str;
			loop = sub;
			while (*loop && *str == *loop)
			{
				str++;
				loop++;
			}
			if (!*loop)
				return (start);
		}
		str++;
	}
	return (NULL);
}
