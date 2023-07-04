/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_of.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 10:42:58 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/02 23:14:37 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_OF_H
# define IMAGE_OF_H

# include <system_of.h>
# include <math_of.h>
# include <pixel_of.h>

typedef enum e_IMAGE_FLIP{
	IMAGE_FLIP_NONE,
	IMAGE_FLIP_HORIZONTAL,
	IMAGE_FLIP_VERTICAL
}t_IMAGE_FLIP;

typedef struct s_image	t_image;
struct s_image{
	B32				id;
	void			*buffer;
	B8				*addr;
	t_vi2d			size[1];
	B32				bpp;
	B32				length;
	B32				endian;
	B32				angle;
	t_pixel			color;
	t_IMAGE_FLIP	flip;
};

extern t_image	*image_of_push(B32 id, void *buffer, t_vi2d size);
extern void   	image_of_pop(t_image *image, void *plugin, t_SystemSet up);

#endif // IMAGE_OF_H