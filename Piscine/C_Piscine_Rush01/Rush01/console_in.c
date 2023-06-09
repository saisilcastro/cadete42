/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console_in.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 16:55:48 by lde-cast          #+#    #+#             */
/*   Updated: 2023/03/12 21:37:27 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	verification(char border[4][4], char *command, int axis[2], int mem)
{
	if (command && *(command + mem) > 48 && *(command + mem) < 53)
	{
		border[axis[1]][axis[0]] = *(command + mem) - 48;
		axis[0]++;
		if (axis[0] > 3)
		{
			axis[0] = 0;
			axis[1]++;
		}
	}
}
