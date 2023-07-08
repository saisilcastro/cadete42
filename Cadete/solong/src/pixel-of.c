/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel-of.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:39:54 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/08 11:39:04 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pixel_of.h>
#include <image_of.h>

void	pixel_rgb_set(t_pixel *set, B8U r, B8U g, B8U b)
{
	if (!set)
		return ;
	set->r = r;
	set->g = g;
	set->b = b;
	set->a = 255;
}

t_pixel	pixel_rgba_local(B8U r, B8U g, B8U b, B8U a)
{
	t_pixel	set;

	set.r = r;
	set.g = g;
	set.b = b;
	set.a = a;
	return (set);
}

void	pixel_from_abgr(t_pixel *set, int color)
{
	set->r = (color >> 0);
	set->g = (color >> 8);
	set->b = (color >> 16);
	set->a = (color >> 24);
}

void	pixel_to_int(void *set, t_pixel *px, t_vi2d pt)
{
	char	*dest;
	t_image	*img;

	img = set;
	if (!set || !px)
		return ;
	if (pt.x < 0)
		pt.x = 0;
	if (pt.x > img->size->x)
		pt.x = img->size->x;
	if (pt.y < 0)
		pt.y = 0;
	if (pt.y > img->size->y)
		pt.y = img->size->y;
	dest = img->addr + (pt.y * img->length + pt.x * (img->bpp / 8));
	*(B32U *)dest = (px->a << 24 | px->b << 16 | px->g << 8 | px->r << 0);
}
