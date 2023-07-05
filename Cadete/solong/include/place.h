/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 07:32:33 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/05 18:14:20 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLACE_H
# define PLACE_H

# include <keyboard_of.h>
# include <machine.h>
# include <plugin/mlx_plugin.h>
# include <system_of.h>

typedef struct s_place	t_place;
struct s_place
{
	t_machine	gear[1];
	t_STATUS	(*start)(t_place *);
	t_image		*(*image_select)(t_place *set, B32 id);
	void		(*image_load_first)(t_place *set, B8 *path, B32 id);
	void		(*image_load_last)(t_place *set, B8 *path, B32 id);
	void		(*map_set)(t_place *set, B32 id);
	void		(*init)(t_place *set, void *data);
	t_STATUS	(*key_down)(t_place *set, t_KEYBOARD_MAP key);
	int			(*update)(t_place *set);
	void		(*run)(t_place *set, void *data);
	void		(*draw_bg)(t_place *set);
	void		(*stop)(t_place *set);
	t_STATUS	(*destroy)(t_place * set);
	void		(*pop)(t_place *set);
};

extern void		place_set(t_place *set, t_SystemSet up, t_vi2d size);
extern t_image	*place_image_select(t_place *set, B32 id);
extern void		place_image_load_first(t_place *set, B8 *path, B32 id);
extern void		place_image_load_last(t_place *set, B8 *path, B32 id);
extern void		place_map_set(t_place *set, B32 id);
extern t_STATUS	place_key_down(t_place *set, t_KEYBOARD_MAP map);
extern void		place_run(t_place *set, void *data);
extern void		place_draw_bg(t_place *set);
extern void		place_stop(t_place *set);
extern t_STATUS	place_destroy(t_place *set);
extern void		place_pop(t_place *set);

#endif // PLACE_H