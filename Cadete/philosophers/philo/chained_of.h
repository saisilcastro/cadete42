/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_of.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 21:36:15 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/29 00:48:14 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAINED_OF_H
# define CHAINED_OF_H

typedef struct s_chained	t_chained;
struct s_chained{
	void		*data;
	t_chained	*prev;
	t_chained	*next;
};

extern t_chained	*chained_push(void *data);
extern int			chained_next_first(t_chained **head, t_chained *set);
extern int			chained_next_last(t_chained **head, t_chained *set);
extern void			chained_pop(t_chained **head);

#endif