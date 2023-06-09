/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:35:15 by lde-cast          #+#    #+#             */
/*   Updated: 2023/03/13 09:59:36 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_game	t_game;
struct s_game{};

void	logic(char border[4][4], char puzzle[4][4], int x, int y)
{
	int	i;

	if (border[y][x] == 4)
	{
		if (y == 0 || y == 1)
		{
			i = -1;
			while (++i < 4)
				puzzle[y + i][x] = i + 1;
		}
		else
		{
			if (y == 2)
			{
				i = -1;
				while (++i < 4)
				{
					//printf("*%i %i", y, i);
					puzzle[x][i] = i + 1;
				}
				//printf("\n");
				}
			else
			{
				i = 4;
				while (--i >= 0)
				{
					//printf("#%i %i", x, 4 - i);
					puzzle[x][i] = 4 - i;
				}
				//printf("\n");
			}
		}
	}
	if (border[y][x] == 1)
	{
		if (y == 0 || y == 1)
			puzzle[x][y] = 4;
		else
		{
			printf("#%i %i\n", x, y);
			puzzle[x][y] = 4;
		}
	}
	if (border[y][x] == 3 && border[y][x + 1] == 2)
	{
		//printf("**%i %i\n", x, y);
	}
}
