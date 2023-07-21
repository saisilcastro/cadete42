/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math-of.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 19:34:01 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/20 09:25:22 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math_of.h>

t_vi2d	vi2d_start(int x, int y)
{
	t_vi2d	set;

	set.x = x;
	set.y = y;
	return (set);
}

t_vf2d	vf2d_start(float x, float y)
{
	t_vf2d	set;

	set.x = x;
	set.y = y;
	return (set);
}
