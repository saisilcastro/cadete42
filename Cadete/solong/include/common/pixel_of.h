/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_of.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 08:20:02 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/20 09:37:57 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIXEL_OF_H
# define PIXEL_OF_H

# include <system_of.h>
# include <math_of.h>

typedef struct s_pixel{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
}t_pixel;

extern void		pixel_rgb_set(t_pixel *set, unsigned char r,
					unsigned char g, unsigned char b);
extern t_pixel	pixel_rgba_local(unsigned char r, unsigned char g,
					unsigned char b, unsigned char a);
extern void		pixel_from_abgr(t_pixel *set, int color);
extern void		pixel_to_int(void *set, t_pixel *px, t_vi2d pt);

#endif // PIXEL_OF_H