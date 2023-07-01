/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 07:32:33 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/01 14:57:58 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLACE_H
# define PLACE_H

# include <system_of.h>
# include <machine.h>

typedef struct s_place	t_place;
struct s_place{
	t_machine	machine[1];
	void		(*init)(t_place *, void *);
	void		(*image_load_first)();
	void		(*update)(t_place *);
	void		(*run)(t_place *, void *);
	void		(*pop)(t_place *);
};

extern void	place_set(t_place *set, t_SystemSet up, t_vi2d size);
extern void	place_run(t_place *set, void *data);
extern void	place_destroy(t_place *set);

#endif // PLACE_H