/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel-of.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:39:54 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/20 09:28:03 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pixel_of.h>
#include <image_of.h>

void	pixel_rgb_set(t_pixel *set, unsigned char r,
	unsigned char g, unsigned char b)
{
	if (!set)
		return ;
	set->r = r;
	set->g = g;
	set->b = b;
	set->a = 255;
}

t_pixel	pixel_rgba_local(unsigned char r,
	unsigned char g, unsigned char b, unsigned char a)
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
	*(unsigned int *)dest = (px->a << 24
			| px->b << 16 | px->g << 8 | px->r << 0);
}
