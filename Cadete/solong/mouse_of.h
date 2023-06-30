/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_of.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 10:43:14 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/30 08:54:54 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_OF_H
# define MOUSE_OF_H

# include "system_of.h"

typedef struct s_mouse{
	B32	x;
	B32	y;
	unsigned	button:MACHINE_MOUSE_MAX;
	unsigned	wheel:MOUSE_WHEEL_MAX;
}t_mouse;

extern void	mouse_of_set(t_mouse *set, B32 x, B32 y,
				unsigned button, unsigned wheel);

#endif // MOUSE_OF_H