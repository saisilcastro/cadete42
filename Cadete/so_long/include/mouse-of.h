/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse-of.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 10:43:14 by lde-cast          #+#    #+#             */
/*   Updated: 2023/05/21 10:43:16 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOUSE_OF_H
#define MOUSE_OF_H

#include <system-of.h>

typedef struct s_mouse t_mouse;
struct s_mouse{
	B32 x, y;
	unsigned button: MACHINE_MOUSE_MAX;
	unsigned wheel: MACHINE_WHEEL_MAX;
};

extern void	mouse_of_set(t_mouse *set, B32 x, B32 y, unsigned button, unsigned wheel);

#endif // MOUSE_OF_H