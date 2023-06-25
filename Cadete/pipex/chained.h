/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 22:39:12 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/25 15:00:51 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAINED_H
#define	CHAINED_H

#include <stdlib.h>

typedef struct s_chained	t_chained;
struct s_chained{
	void		*data;
	t_chained	*prev;
	t_chained	*next;	
};

extern t_chained	*chained_push(void *data);
extern void			chained_next_first(t_chained **head, t_chained *next);
extern void			chained_next_last(t_chained **head, t_chained *next);
extern void			chained_pop(t_chained **head);

#endif // CHAINED_H