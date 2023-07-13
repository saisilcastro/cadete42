/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_of.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:47:35 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/13 18:17:51 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_OF_H
# define MAP_OF_H

# include <system_of.h>
# include <math_of.h>
# include <stdlib.h>

typedef struct s_map	t_map;
struct s_map{
	char	**data;
	t_vi2d	begin[1];
	t_vi2d	pos[1];
	t_vi2d	size[1];
	B32		collectable;
};

typedef enum{
	MAP_NOT_CREATED = -3,
	MAP_INVALID_TOP_BOTTOM = -2,
	MAP_INVALID_MID_BORDER = -1,
	MAP_NO_ERROR = 1
}t_map_error;

extern void			map_set(t_map *map);
extern void			map_load(t_map *map, char *path);
extern t_map_error	map_border_validator(t_map *map);
extern t_map_error	map_flood_fill(t_map *map);
extern t_map_error	map_validate(t_map *map);
extern void			map_pop(t_map *map);

#endif // MAP_OF_H