/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel_of.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 08:20:02 by mister-code       #+#    #+#             */
/*   Updated: 2023/06/30 08:53:28 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIXEL_OF_H
# define PIXEL_OF_H

# include <system_of.h>

typedef struct s_pixel{
	B8U	r;
	B8U	g;
	B8U	b;
	B8U	a;
}t_pixel;

extern void		pixel_rgb_set(t_pixel *set, B8U r, B8U g, B8U b);
extern t_pixel	pixel_rgba_local(B8U r, B8U g, B8U b, B8U a);

#endif // PIXEL_OF_H