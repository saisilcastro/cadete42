/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math-of.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:34:01 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/30 19:35:46 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math_of.h>

t_vi2d	vi2d_start(B32 x, B32 y)
{
	t_vi2d	set;

	set.x = x;
	set.y = y;
	return (set);
}

t_vf2d	vf2d_start(BP32 x, BP32 y)
{
	t_vf2d	set;

	set.x = x;
	set.y = y;
	return (set);
}
