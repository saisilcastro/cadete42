/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 10:21:27 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/21 16:42:56 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include <place.h>
# include <map_of.h>

enum e_image_row{
	GRASS_IMG = 1,
	TREE_IMG,
	JEWEL_IMG,
	EXIT_IMG,
	TWINSEN_FRONT,
	TWINSEN_DG_FT,
	TWINSEN_DG_FT_LEFT,
	TWINSEN_BACK,
	TWINSEN_DG_BACK,
	TWINSEN_DG_BACK_LEFT,
	TWINSEN_SIDE,
	TWINSEN_SIDE_LEFT,
	ENEMY_ONE,
	ENEMY_TWO,
	ENEMY_THREE,
	ENEMY_FOUR
};

extern void	image_create(t_place *set, t_map *map, t_vi2d *pos, t_vi2d id);
extern void	image_animation(t_place *set, t_object *obj);
extern void	object_create(t_place *set, t_map *map);
extern void	so_long_execute(char *path);

#endif // SO_LONG_BONUS_H