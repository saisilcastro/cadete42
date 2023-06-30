/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image-of.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 12:42:59 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/19 14:56:18 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <image-of.h>
#include <mlx.h>

t_image	image_of_init(t_vi2d size, t_pixel color)
{
	t_image	set;

	set.buffer = NULL;
	set.addr = NULL;
	set.size->x = size.x;
	set.size->y = size.y;
	set.bpp = 0;
	set.length = 0;
	set.endian = 0;
	set.angle = 0;
	set.color = color;
	return (set);
}

t_image	image_of_create_start(void *plugin, t_vi2d size)
{
	t_image	set;

	set.id = 0;
	set.size->x = size.x;
	set.size->y = size.y;
	set.buffer = mlx_new_image(plugin, set.size->x, set.size->y);
	set.addr = mlx_get_data_addr(set.buffer, &set.bpp,
			&set.length, &set.endian);
	set.color = pixel_rgba_local(255, 255, 255, 255);
	return (set);
}

t_image	image_of_buffer_init(void *buffer, t_vi2d size)
{
	t_image	set;

	set.id = 0;
	set.buffer = buffer;
	set.size->x = size.x;
	set.size->y = size.y;
	set.addr = mlx_get_data_addr(set.buffer, &set.bpp,
			&set.length, &set.endian);
	set.color = pixel_rgba_local(255, 0, 0, 255);
	return (set);
}

void	image_of_start(t_image *set, B32 id, t_vi2d size, t_pixel color)
{
	if (!set)
		return ;
	set->id = id;
	set->buffer = NULL;
	set->addr = NULL;
	set->size->x = size.x;
	set->size->y = size.y;
	set->bpp = 0;
	set->length = 0;
	set->endian = 0;
	set->angle = 0;
	set->color = color;
}

t_image	*image_of_set(void *plugin, B32 id, t_vi2d size)
{
	t_image	*get;

	get = (t_image *)malloc(sizeof(t_image));
	if (!get || !plugin)
		return (NULL);
	get->id = id;
	get->size->x = size.x;
	get->size->y = size.y;
	get->buffer = mlx_new_image(plugin, get->size->x, get->size->y);
	get->addr = mlx_get_data_addr(get->buffer, &get->bpp,
			&get->length, &get->endian);
	get->color = pixel_rgba_local(255, 255, 255, 255);
	return (get);
}

t_image	*image_of_buffer(void *buffer, B32 id, t_vi2d size)
{
	t_image	*get;

	get = (t_image *)malloc(sizeof(t_image));
	get->id = id;
	get->size->x = size.x;
	get->size->y = size.y;
	get->buffer = buffer;
	get->addr = mlx_get_data_addr(get->buffer, &get->bpp,
			&get->length, &get->endian);
	get->color = pixel_rgba_local(255, 0, 0, 255);
	return (get);
}

void	image_of_destroy(void *plugin, t_image *image)
{
	if (!plugin || !image || !image->buffer)
		return ;
	mlx_destroy_image(plugin, image->buffer);
	//image->buffer = NULL;
}
