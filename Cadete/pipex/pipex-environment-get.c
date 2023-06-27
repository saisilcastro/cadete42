/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex-environment-get.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 04:17:59 by mister-code       #+#    #+#             */
/*   Updated: 2023/06/26 22:46:50 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*ft_strsub(char *str, char *sub);
static int	ft_strlen(char *str);
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

static char	*path_allocate(char *str, int len)
{
	int		pos;
	char	*buffer;

	buffer = (char *)malloc((len + 1) * sizeof(char));
	pos = 0;
	while (pos < len)
	{
		*(buffer + pos) = *(str + pos);
		pos++;
	}
	*(buffer + pos) = '\0';
	return (buffer);
}

static void	path_split(t_pipe *set, char *str)
{
	char	*buffer;
	char	*remain;

	if (!set || !str)
		return ;
	buffer = str;
	while (buffer)
	{
		remain = ft_strsub(buffer, ":");
		if (remain)
			chained_next_last(&set->path,
				chained_push(path_allocate(buffer, remain - buffer)));
		if (buffer && remain)
			buffer = remain + 1;
		if (!remain)
			break ;
	}
	if (buffer)
		chained_next_last(&set->path,
			chained_push(path_allocate(buffer, ft_strlen(buffer) + 1)));
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

static int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*(str + len))
		len++;
	return (len);
}
