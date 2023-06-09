/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 21:28:53 by lde-cast          #+#    #+#             */
/*   Updated: 2023/03/12 21:32:10 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	up_verification(char puzzle[4][4], int pos, int max, char border[4][4]);
int	down_verification(char puzzle[4][4], int pos, int max, char border[4][4]);
int	left_verification(char puzzle[4][4], int pos, int max, char border[4][4]);
int	right_verification(char puzzle[4][4], int pos, int max, char border[4][4]);

int	verify_extremity(char puzzle[4][4], int pos, int max, char border[4][4])
{
	if (left_verification(puzzle, pos, max, border) == 1)
		return (1);
	if (right_verification(puzzle, pos, max, border) == 1)
		return (1);
	if (down_verification(puzzle, pos, max, border) == 1)
		return (1);
	if (up_verification(puzzle, pos, max, border) == 1)
		return (1);
	return (0);
}
