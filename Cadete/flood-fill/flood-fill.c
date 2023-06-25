#include "flood-fill.h"

void file_get_size(const char *path, int *w, int *h)
{
	int fd;
	int	size;
	int len;
	char buffer[BUFFER_SIZE];

	fd = open(path, O_RDONLY);
	if (fd <= 0)
		return ;
	size = read(fd, buffer, BUFFER_SIZE);
	len = 0;
	while (len < size)
	{
		if (*(buffer + len) == '\n')
			break ;
		len++;
	}
	*w = len;
	*h = size / (float)len;
	close(fd);
}

char	*buffer_load(const char *path)
{
	int		fd;
	int		size;
	int		pos;
	char	content[BUFFER_SIZE];
	char	*buffer;

	fd = open(path, O_RDONLY);
	if (fd <= 0)
		return (0);
	size = read(fd, content, BUFFER_SIZE);
	if (size <= 0)
		return (NULL);
	buffer = (char *)malloc((size + 1) * sizeof(char));
	if (buffer)
	{
		pos = 0;
		while (*(content + pos))
		{
			*(buffer + pos) = *(content + pos);
			pos++;
		}
	}
	close(fd);
	return (buffer);
}

char	**map_get(const char *path, int *w, int *h)
{
	int		i;
	int		j;
	int		fd;

	char	**map;
	char	*buffer;

	file_get_size(path, w, h);
	buffer = buffer_load(path);
	map = (char **)malloc(*h * sizeof(char*));
	map[0] = (char *)malloc(*w * *h * sizeof(char));
	i = 0;
	j = 0;
	while (*(buffer + i))
	{
		if (*(buffer + i) != '\n')
		{
			map[j / *w][j % *w] = *(buffer + i);
			printf("%c.", map[j / *w][j % *w]);
			j++;
		}
		i++;
	}
	free(buffer);
	free(map);
	return (NULL);
}