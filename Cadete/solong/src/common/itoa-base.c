/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa-base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 20:33:07 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/21 23:05:13 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <itoa_base.h>
#include <stdio.h>

void	itoa_base(void	*plugin, t_conf *c, int nb, int base)
{
	int				mul;

	if (nb < 0)
		mlx_putchar(plugin, '-', c->pos[0], c->color);
	mul = 1;
	if (nb <= -base || nb >= base)
	{
		itoa_base(plugin, c, nb / base, base);
		nb %= base;
	}
	if (nb < 0)
		mul = -1;
	mlx_putchar(plugin, (nb * mul) + 48, c->pos[0], c->color);
	c->pos->x += 10;
}
