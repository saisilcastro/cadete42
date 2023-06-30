/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel-of.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 10:42:39 by lde-cast          #+#    #+#             */
/*   Updated: 2023/05/21 10:42:41 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pixel-of.h>

void pixel_rgba_set(t_pixel *set, B8U r, B8U g, B8U b, B8U a)
{
	if (!set)
		return ;
	set->r = r;
	set->g = g;
	set->b = b;
	set->a = a;
}

t_pixel pixel_rgba_local(B8U r, B8U g, B8U b, B8U a)
{
	t_pixel set;
	
	set.r = r;
	set.g = g;
	set.b = b;
	set.a = a;
	return (set);
}