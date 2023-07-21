/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 15:47:19 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/17 18:07:52 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <place.h>
# include <map_of.h>

extern void	image_create(t_place *set, t_map *map, t_vi2d *pos, t_vi2d id);
extern void	object_create(t_place *set, t_map *map);
extern void	so_long_execute(char *path);

#endif // SO_LONG_H