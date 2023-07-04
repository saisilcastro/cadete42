/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixe-of.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:39:54 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/02 16:41:43 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pixel_of.h>

void		pixel_rgb_set(t_pixel *set, B8U r, B8U g, B8U b)
{
    if (!set)
        return ;
    set->r = r;
    set->g = g;
    set->b = b;
}

t_pixel	pixel_rgba_local(B8U r, B8U g, B8U b, B8U a)
{
    t_pixel set;

    set.r = r;
    set.g = g;
    set.b = b;
    set.a = a;
    return (set);
}