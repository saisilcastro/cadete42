/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image-of.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:00:21 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/06 19:48:18 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <image_of.h>
#include <mlx.h>
#include <stdlib.h>

t_image	*image_of_push(B32 id, void *buffer, t_vi2d size)
{
	t_image	*set;

	set = (t_image *)malloc(sizeof(t_image));
	if (!set)
		return (NULL);
	set->id = id;
	set->buffer = buffer;
	set->addr = NULL;
	set->size[0] = vi2d_start(size.x, size.y);
	set->bpp = 1;
	set->angle = 0;
	set->length = 0;
	set->endian = 0;
	set->flip = IMAGE_FLIP_NONE;
	pixel_rgb_set(&set->color, 255, 255, 255);
	return (set);
}

t_status	image_of_id(t_image *set, B32 id)
{
	if (!set || set->id != id)
		return (Off);
	return (On);
}

B32U	image_color_int(t_image *data, B32 x, B32 y)
{
	if (!data)
		return (0);
	return (*(B32U *)(data->addr + (y * data->length + x * (data->bpp / 8))));
}

void	image_pixel_to(t_image *data, t_pixel *px, t_vi2d pt)
{
	char	*dest;

	if (!data || !px)
		return ;
	dest = data->addr + (pt.y * data->length + pt.x * (data->bpp / 8));
	*(B32U *)dest = (px->a << 24 | px->r << 16 | px->g << 8 | px->b);
}

void	image_of_pop(t_image *image, void *plugin, t_SystemSet up)
{
	if (!image)
		return ;
	if (up.system == SYSTEM_CONSOLE)
		free(image);
	else if (up.system == SYSTEM_MINILIBX)
	{
		if (image->buffer)
			mlx_destroy_image(plugin, image->buffer);
	}
}
