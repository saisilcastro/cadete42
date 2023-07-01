/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 07:32:33 by mister-code       #+#    #+#             */
/*   Updated: 2023/06/30 19:23:37 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLACE_H
# define PLACE_H

# include <system_of.h>
# include <machine.h>

typedef struct s_place	t_place;
struct s_place{
	t_machine	machine[1];
	void		(*init)(t_place *);
	void		(*image_load_first)();
	void		(*update)(t_place *);
	void		(*run)(t_place *);
	void		(*pop)(t_place *);
};

extern void	place_set(t_place *set, t_SystemSet up);
extern void	place_run(t_place *set);
extern void	place_destroy(t_place *set);

#endif // PLACE_H