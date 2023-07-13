/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_of.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:47:35 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/12 17:31:29 by lde-cast         ###   ########.fr       */
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
	t_vi2d	pos[1];
	t_vi2d	size[1];
};

extern void		map_set(t_map *map);
extern void		map_load(t_map *map, char *path);
extern t_status	map_validate(t_map *map);
extern void		map_pop(t_map *map);

#endif // MAP_OF_H