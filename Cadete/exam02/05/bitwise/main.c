/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 12:35:50 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/06 12:46:52 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

typedef struct s_pixel	t_pixel;
struct s_pixel{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
	unsigned char	a;
};

void	pixel_get(t_pixel *set, int color)
{
	set->r = (color >> 0);
	set->g = (color >> 8);
	set->b = (color >> 16);
	set->a = (color >> 24);
}

int	main(void)
{
	int		color;
	t_pixel	pixel;

	color = (255 << 24 | 250 << 16 | 0 << 8 | 230);
	pixel_get(&pixel, color);
	printf("hello world %i %i %i %i\n", pixel.a, pixel.r, pixel.g, pixel.b);
	return (0);
}
