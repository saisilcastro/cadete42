/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command-get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 11:49:17 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/22 12:32:21 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <command_of.h>

static int	has_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n'
		|| c == '\v' || c == '\f')
		return (1);
	return (0);
}

void	command_get(t_command **head, char *command)
{
	char	buffer[1024];
	int		i;

	if (!command)
		return ;
	while (*command)
	{
		i = 0;
		while (*command && !has_space(*command))
		{
			*(buffer + i++) = *command;
			command++;
		}
		if (i)
		{
			*(buffer + i) = '\0';
			command_next_last(head, command_push(buffer));
			while (*command && has_space(*command))
				command++;
		}
		if (!*command)
			break ;
	}
}
