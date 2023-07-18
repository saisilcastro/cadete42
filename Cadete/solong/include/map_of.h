/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_of.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:47:35 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/17 22:02:23 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_OF_H
# define MAP_OF_H

# include <system_of.h>
# include <math_of.h>
# include <stdlib.h>

typedef struct s_map	t_map;
struct s_map{
	B8		**data;
	B8		**validator;
	t_vi2d	begin[1];
	t_vi2d	pos[1];
	t_vi2d	size[1];
	B32		collectable;
};

typedef enum e_map_error{
	MAP_NOT_CREATED = -8,
	MAP_INVALID_TOP_BOTTOM,
	MAP_INVALID_MID_BORDER,
	MAP_MULTIPLE_START_POINT,
	MAP_MULTIPLE_EXIT,
	MAP_COLLECTABLE_INACCESSIBLE,
	MAP_EXIT_INACCESSIBLE,
	MAP_ENEMY_TRAP,
	MAP_OBJECT_INVALID,
	MAP_NO_ERROR
}t_map_error;

extern void			map_set(t_map *map);
extern void			map_load(t_map *map, B8 *path);
extern void			map_size(t_map *map, B8 *buffer, B32 fd);
extern t_map_error	map_border_validator(t_map *map);
extern t_map_error	map_flood_fill(t_map *map);
extern t_map_error	map_validate(t_map *map);
extern void			map_pop(t_map *map);

#endif //MAP_OF_H