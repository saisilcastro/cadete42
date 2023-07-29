/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 21:24:52 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/29 00:33:23 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIFE_H
# define LIFE_H

# include <timer_of.h>
# include <chained_of.h>

typedef struct s_life	t_life;
struct s_life{
	t_timer			timer[1];
	t_chained		*man;
};

extern void	life_set(t_life *set);
extern void	life_update(t_life *set);
extern void	life_pop(t_life *set);

#endif