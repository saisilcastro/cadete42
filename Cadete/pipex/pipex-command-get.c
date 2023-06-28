/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex-command-get.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 23:32:59 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/28 01:01:00 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "command_of.h"

static void			command_break(t_pipe *set, char *command);
static char			*name_get(char *command, char name[], int *pos);
static t_chained	*flag_get(char *command, int *pos);

void	pipe_command_get(t_pipe *set, int argc, char **argv)
{
	int	pos;

	if (!set || argc < 5)
		return ;
	pos = 2;
	while (pos < argc - 1)
	{
		command_break(set, *(argv + pos));
		pos++;
	}
}

static void	command_break(t_pipe *set, char *command)
{
	char		buffer[16];
	char		*name;
	int			pos;
	t_chained	*flag;

	if (!command || !set)
		return ;
	flag = NULL;
	pos = 0;
	name = name_get(command, buffer, &pos);
	flag = flag_get(command, &pos);
	chained_next_last(&set->cmd, chained_push(command_push(name, flag)));
	set->descriptor->max++;
}

static char	*name_get(char *command, char name[], int *pos)
{
	int		i;
	char	*buffer;

	if (!command)
		return (NULL);
	while (*(command + *pos) == ' ')
		*pos += 1;
	i = 0;
	while (*(command + *pos) && *(command + *pos) != ' ')
	{
		*(name + i) = *(command + *pos);
		*pos += 1;
		i++;
	}
	*(name + i) = '\0';
	while (*(command + *pos) && *(command + *pos) != '-')
		*pos += 1;
	buffer = ft_strdup(name);
	return (buffer);
}

static void	flag_loop(char *command
	, int *pos, t_chained **flag)
{
	char		buffer[64];
	int			i;

	if (!command || *(command + *pos) == '\0')
		return ;
	i = 0;
	while (*(command + *pos))
	{
		while (*(command + *pos) && *(command + *pos) == ' ')
			*pos += 1;
		if (*(command + *pos) == '\0')
			break ;
		*(buffer + i) = *(command + *pos);
		if (*(command + *pos) == '-' && i > 1)
		{
			*(buffer + i) = '\0';
			chained_next_last(flag, chained_push(ft_strdup(buffer)));
			i = 0;
		}
		i++;
		*pos += 1;
	}
	if (*pos - i > 0)
		*pos -= i;
}

static t_chained	*flag_get(char *command, int *pos)
{
	t_chained	*flag;
	char		buffer[32];
	int			i;

	if (!command || *(command + *pos) == '\0')
		return (NULL);
	flag = NULL;
	flag_loop(command, pos, &flag);
	while (*(command + *pos) && *(command + *pos) == ' ')
		*pos += 1;
	if (!*(command + *pos))
		return (flag);
	i = 0;
	while (*(command + *pos))
	{
		*(buffer + i) = *(command + *pos);
		i++;
		*pos += 1;
	}
	*(buffer + i) = '\0';
	chained_next_last(&flag, chained_push(ft_strdup(buffer)));
	return (flag);
}
