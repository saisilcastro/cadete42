/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 19:36:23 by lde-cast          #+#    #+#             */
/*   Updated: 2023/03/13 12:25:26 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_twice(char puzzle[4][4], int pos, int max, int num)
{
	int	i;

	i = -1;
	while (++i < pos >> 2)
		if (puzzle[i][pos % max] == num)
			return (1);
	i = -1;
	while (++i < pos % max)
		if (puzzle[pos >> 2][i] == num)
			return (1);
	return (0);
}

int	up_verification(char puzzle[4][4], int pos, int max, char border[4][4])
{
	int	i;
	int	min;
	int	count;

	i = 0;
	min = 0;
	count = 0;
	if (pos >> 2 == 3)
	{
		while (i < 4)
		{
			if (puzzle[i][pos % max] > min)
			{
				min = puzzle[i][pos % max];
				count++;
			}
			i++;
		}
		if (border[0][pos % max] != count)
			return (1);
	}
	return (0);
}

int	down_verification(char puzzle[4][4], int pos, int max, char border[4][4])
{
	int	i;
	int	min;
	int	count;

	i = 3;
	min = 0;
	count = 0;
	if (pos >> 2 == 3)
	{
		while (i >= 0)
		{
			if (puzzle[i][pos % max] > min)
			{
				min = puzzle[i][pos % max];
				count++;
			}
			i--;
		}
		if (border[1][pos % max] != count)
			return (1);
	}
	return (0);
}

int	left_verification(char puzzle[4][4], int pos, int max, char border[4][4])
{cation(char puzzle[4][4], int pos, int max, char border[4][4])
{
	int	i;
	int	max_size;
	int	visible_towers;

	int	i;
	int	min;
	int	count;

	i = 0;
	min = 0;
	count = 0;
	if (pos % 4 == 3)
	{
		while (i < 4)
		{
			if (puzzle[pos >> 2][i] > min)
			{
				min = puzzle[pos >> 2][i];
				count++;
			}
			i++;
		}
		if (border[2][pos % max] != count)
			return (1);
	}
	return (0);
}

int	right_verification(char puzzle[4][4], int pos, int max, char border[4][4])
{
	int	i;
	int	max_size;
	int	visible_towers;

	i = 4;
	max_size = 0;
	visible_towers = 0;
	if (pos % 4 == 3)
	{
		while (--i >= 0)
		{
			if (puzzle[pos / max][i] > max_size)
			{
				max_size = puzzle[pos / max][i];
				visible_towers++;
			}
		}
		if (border[3][pos % max] != visible_towers)
			return (1);
	}
	return (0);
}
