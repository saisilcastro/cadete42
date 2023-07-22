/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_print.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 16:54:39 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/21 18:38:58 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLACE_PRINT_H
# define PLACE_PRINT_H

# include <place.h>
# include <math_of.h>

typedef struct s_conf	t_conf;
struct s_conf{
	t_vi2d	pos[1];
	int		color;
};

extern t_conf	conf_start(t_vi2d pos, t_pixel color);
extern void		place_print(t_place *set, t_conf conf, char *str, ...);

#endif // PLACE_PRINT_H