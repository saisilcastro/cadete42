/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_of.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 08:23:05 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/14 22:15:04 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATH_OF_H
# define MATH_OF_H

# include "system_of.h"

typedef struct s_vi2d{
	B32	x;
	B32	y;
}t_vi2d;

typedef struct s_vi3d	t_vi32;
struct s_vi3d{
	B32	x;
	B32	y;
	B32	z;
};

extern t_vi2d	vi2d_start(B32 x, B32 y);

typedef struct s_vf2d	t_vf2d;
struct s_vf2d{
	BP32	x;
	BP32	y;
};

typedef struct s_vf3d	t_vf3d;
struct s_vf3d{
	BP32	x;
	BP32	y;
	BP32	z;
};

extern t_vf2d	vf2d_start(BP32 x, BP32 y);

#endif // MATH_OF_H