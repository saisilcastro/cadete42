/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 07:32:33 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/06 14:35:54 by mister-code      ###   ########.fr       */
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
	t_status	(*start)(t_place *);
	t_image		*(*image_select)(t_place *set, B32 id);
	void		(*image_load_first)(t_place *set, B8 *path, B32 id);
	void		(*image_load_last)(t_place *set, B8 *path, B32 id);
	t_status	(*object_select)(t_place * set, B32 id);
	void		(*object_next_first)(t_place *set, B32 id,
			t_vi2d pos, t_image *image);
	void		(*object_next_last)(t_place *set, B32 id,
			t_vi2d pos, t_image *image);
	void		(*map_set)(t_place *set, B32 id);
	void		(*init)(t_place *set, void *data);
	t_status	(*key_down)(t_place * set, t_keyboard_map key);
	int			(*update)(t_place *set);
	void		(*run)(t_place *set, void *data);
	void		(*draw_bg)(t_place *set);
	void		(*draw)(t_place *set);
	void		(*stop)(t_place *set);
	t_status	(*destroy)(t_place * set);
	void		(*pop)(t_place *set);
};

extern void		place_set(t_place *set, t_SystemSet up, t_vi2d size);
extern t_image	*place_image_select(t_place *set, B32 id);
extern void		place_image_load_first(t_place *set, B8 *path, B32 id);
extern void		place_image_load_last(t_place *set, B8 *path, B32 id);
extern t_status	place_object_select(t_place *set, B32 id);
extern void		place_object_next_first(t_place *set, B32 id,
					t_vi2d pos, t_image *image);
extern void		place_object_next_last(t_place *set, B32 id,
					t_vi2d pos, t_image *image);
extern void		place_map_set(t_place *set, B32 id);
extern t_status	place_key_down(t_place *set, t_keyboard_map map);
extern void		place_run(t_place *set, void *data);
extern void		place_draw_bg(t_place *set);
extern void		place_draw(t_place *set);
extern void		place_stop(t_place *set);
extern t_status	place_destroy(t_place *set);
extern void		place_pop(t_place *set);

#endif // PLACE_H