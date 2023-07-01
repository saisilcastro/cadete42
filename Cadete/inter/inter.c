#include <unistd.h>

void print(char *first, char *second)
{
	char	table[256];
	int		i;
	int		j;

	i = 0;
	while (i < 256)
	{
		j = 0;
		while (*(second + j))
		{
			if (*(second + j) == i)
				*(table + i) = 1;
			j++;
		}
		i++;
	}
	i = 0;
	while (*(first + i))
	{
		j = 0;
		while (j < 256)
		{
			if (*(table + j) == 1 && *(first + i) == j)
			{
				write(1, &j, 1);
				*(table + j) = 0;
			}
			j++;
		}
		i++;
	}
}

int main(int argc, char **argv)
{
	if (argc != 3)
		write(1, "\n", 1);
	else
		print(argv[1], argv[2]);
	return (0);
}
