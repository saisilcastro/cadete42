/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 07:32:33 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/03 17:46:50 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLACE_H
# define PLACE_H

# include <system_of.h>
# include <machine.h>
# include <plugin/mlx_plugin.h>

typedef struct s_place	t_place;
struct s_place{
	t_machine	gear[1];
	t_STATUS	(*start)(t_place *);
	t_image		*(*image_select)(t_place *, B32);
	void		(*image_load_first)(t_place *, B8 *, B32);
	void		(*image_load_last)(t_place *, B8 *, B32);
	void		(*map_set)(t_place *, B32);
	void		(*init)(t_place *, void *);
	t_STATUS	(*key_get)(t_place *, t_KEYBOARD_MAP);
	int			(*update)(t_place *);
	void		(*stop)(t_place *);
	t_STATUS	(*destroy)(t_place *);
	void		(*run)(t_place *, void *);
	void		(*pop)(t_place *);
};

extern void		place_set(t_place *set, t_SystemSet up, t_vi2d size);
extern t_image *place_image_select(t_place *set, B32 id);
extern void		place_image_load_first(t_place *set, B8 *path, B32 id);
extern void		place_image_load_last(t_place *set, B8 *path, B32 id);
extern void		place_map_set(t_place *set, B32 id);
extern void		place_run(t_place *set, void *data);
extern void		place_stop(t_place *set);
extern t_STATUS	place_destroy(t_place *set);
extern void		place_pop(t_place *set);

#endif // PLACE_H