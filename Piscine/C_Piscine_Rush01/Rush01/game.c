/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:01:35 by lde-cast          #+#    #+#             */
/*   Updated: 2023/03/13 14:18:13 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <malloc.h>
#include <stdio.h>

typedef struct s_game	t_game;
struct s_game{
	unsigned char	size;
	char			puzzle[4][4];
	char			border[4][4];
};

void	verification(char border[4][4], char *command, int axis[2], int mem);
int		check_twice(char border[4][4], int pos, int max, int num);
int		verify_extremity(char p[4][4], int pos, int m, char b[4][4]);

void	input_game(char *str, t_game *game)
{
	int		mem;
	int		axis[2];
	char	*command;

	game->size = 4;
	mem = 0;
	axis[0] = 0;
	axis[1] = 0;
	command = &str[0];
	while (*str && mem < (game->size << 3) - 1)
	{
		if (*str == ' ')
		{
			if (str++ && !*str)
				return ;
			mem++;
			*(command + mem) = *str;
		}
		if (mem == 0)
			*(command + 0) = *str;
		verification(game->border, command, axis, mem);
		mem++;
		str++;
	}
}

int	sort(t_game *game, int current)
{
	int	size;
	int	max;
	int	pos;
	int	memory;

	if (current == game->size << 2)
		return (1);
	size = 0;
	max = game->size;
	while (++size <= game->size)
	{
		pos = -1;
		while (++pos < game->size << 2)
		{
			memory = game->border[pos / max][pos % max];
			if (check_twice(game->puzzle, pos, max, memory) == 0)
			{				
				game->puzzle[pos / game->size][pos % game->size] = size;
				if (verify_extremity(game->puzzle, pos, max, game->border))
				{
					printf("%i\n", size);
					if (sort(game, current + 1) == 1)
						return (1);
				}
				else
					game->puzzle[pos / game->size][pos % game->size] = 0;
			}
		}
	}
	return (0);
}

void	show(t_game *game)
{
	int	pos;
	int	number;
	t_game local;

	pos = -1;
	while (++pos < game->size << 2)
	{
		number = game->puzzle[pos / game->size][pos % game->size] + 48;
		if (number < 49)
			number = 49;
		if (number > 52)
			number = 52;
		write(1, &number, 1);
		if (pos % game->size == game->size - 1)
			write(1, "\n", 1);
	}
}

int	loop(int *current, int max)
{
	int	update;

	if (*current == max)
		return (1);
	update = *current + 1;
	if (loop(&update, max) == 1)
		return (1);
	return (0);
}

void	main_loop(char *argv)
{
	t_game	game;

	input_game(argv, &game);
	if (sort(&game, 0) == 1)
		show(&game);
}
