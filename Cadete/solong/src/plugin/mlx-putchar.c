/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx-putchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:33:36 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/21 20:47:19 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx_plugin.h>
#include <place_print.h>
#include <stdio.h>

void	mlx_putchar(t_mlx_plugin *p, char c, t_vi2d pos, int color)
{
	char	text[2];

	if (!c)
		return ;
	*(text + 0) = c;
	*(text + 1) = '\0';
	mlx_string_put(p->mlx, p->window, pos.x, pos.y, color, text);
}
