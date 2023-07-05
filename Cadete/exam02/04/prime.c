#include <stdio.h>
#include <stdlib.h>

void fprime(int number)
{
	int	prime;

	if (number == 1)
	{
		printf("1");
		return ;
	}
	prime = 2;
	while (number > 1)
	{
		if (number % prime == 0)
		{
			printf("%i", prime);
			number /= prime;
			if (number > 1)
				printf("*");
			prime--;
		}
		prime++;
	}
}

int main(int argc, char **argv)
{
	if (argc == 2 && *argv[1])
		fprime(atoi(argv[1]));
	printf("\n");
}
