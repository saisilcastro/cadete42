/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_of.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 08:23:05 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/20 09:15:41 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_OF_H
# define MATH_OF_H

# include "system_of.h"

typedef struct s_vi2d{
	int	x;
	int	y;
}t_vi2d;

typedef struct s_vi3d	t_vi32;
struct s_vi3d{
	int	x;
	int	y;
	int	z;
};

extern t_vi2d	vi2d_start(int x, int y);

typedef struct s_vf2d	t_vf2d;
struct s_vf2d{
	float	x;
	float	y;
};

typedef struct s_vf3d	t_vf3d;
struct s_vf3d{
	float	x;
	float	y;
	float	z;
};

extern t_vf2d	vf2d_start(float x, float y);

#endif // MATH_OF_H