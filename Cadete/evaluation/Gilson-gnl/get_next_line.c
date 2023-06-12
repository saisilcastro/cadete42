/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gifiguei <gifiguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 13:44:05 by gifiguei          #+#    #+#             */
/*   Updated: 2023/06/11 19:27:39 by gifiguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_read_fd(int fd, char *buffer, char *content, char *remainder);
static char	*ft_current_line(char *content);
static char	*ft_get_rest(char *buffer);

char	*get_next_line(int fd)
{
	static char		*rest;
	char			*actual_line;
	char			*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	actual_line = NULL;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	actual_line = ft_read_fd(fd, buffer, actual_line, rest);
	if (rest)
	{
		free(rest);
		rest = NULL;
	}
	if (actual_line && ft_strchr(actual_line, '\n'))
	{
		rest = ft_get_rest(actual_line);
		actual_line = ft_current_line(actual_line);
	}
	free(buffer);
	return (actual_line);
}

static char	*ft_read_fd(int fd, char *buffer, char *content, char *rest)
{
	int		bytes_read;

	if (rest)
		content = ft_strdup(rest);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			if (content)
				return (content);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		content = ft_strjoin(content, buffer);
		if (ft_strchr(content, '\n'))
			break ;
	}
	return (content);
}

static char	*ft_current_line(char *content)
{
	int			len;
	char		*line;

	len = 0;
	while (content[len] && content[len] != '\n')
		len++;
	if (content[len] == '\n')
		len++;
	line = malloc((len + 1) * sizeof(char));
	if (line)
	{
		ft_memmove(line, content, len);
		line[len] = '\0';
	}
	free(content);
	return (line);
}

static char	*ft_get_rest(char *buffer)
{
	int		i;
	int		len;
	char	*rest;

	i = 0;
	len = 0;
	rest = NULL;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	len = ft_strlen(buffer);
	if (buffer[i] != '\0')
	{
		rest = malloc((len - i + 1) * sizeof(char));
		if (rest)
		{
			ft_memmove(rest, &buffer[i], (len - i + 1));
		}
	}
	return (rest);
}
