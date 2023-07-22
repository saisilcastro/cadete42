/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place-print_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 22:04:33 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/21 23:24:34 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <place_print.h>
#include <itoa_base.h>
#include <stdarg.h>

t_conf	conf_start(t_vi2d pos, t_pixel color)
{
	t_conf	set;

	set.pos[0] = vi2d_start(pos.x, pos.y);
	set.color = (color.a << 24 | color.r << 16 | color.g << 8 | color.b);
	return (set);
}

void	place_print(t_place *set, t_conf c, char *str, ...)
{
	va_list			list;	

	if (!set || !str)
		return ;
	va_start(list, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'd' || *str == 'i')
				itoa_base(set->gear->plugin, &c, va_arg(list, int), 10);
			if (!*str)
				break ;
		}
		else
			mlx_putchar(set->gear->plugin,*str, c.pos[0], c.color);
		c.pos->x += 10;
		str++;
	}
	va_end(list);
}
