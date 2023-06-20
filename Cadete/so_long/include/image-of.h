/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image-of.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 10:42:58 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/19 14:50:11 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_OF_H
# define IMAGE_OF_H

# include <system-of.h>
# include <math-of.h>
# include <pixel-of.h>

typedef enum {
	IMAGE_FLIP_NONE, IMAGE_FLIP_HORIZONTAL, IMAGE_FLIP_VERTICAL
} IMAGE_FLIP;

typedef struct s_image  t_image;
struct s_image{
    B32         id;
    void        *buffer;
    B8          *addr;
    t_vi2d      size[1];
    B32         bpp;
    B32         length;
    B32         endian;
    B32         angle;
    t_pixel     color;
    IMAGE_FLIP  flip;
};

extern t_image  image_of_init(t_vi2d size, t_pixel color);
extern t_image	image_of_create_start(void *plugin, t_vi2d size);
extern t_image	image_of_buffer_init(void *buffer, t_vi2d size);
extern void     image_of_start(t_image *set, B32 id, t_vi2d size, t_pixel color);
extern t_image  *image_of_set(void *plugin, B32 id, t_vi2d size);
extern t_image	*image_of_buffer(void *buffer, B32 id, t_vi2d size);
extern void     image_of_destroy(void *plugin, t_image *image);

#endif // IMAGE_OF_H