/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 22:39:12 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/27 13:31:50 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAINED_H
# define CHAINED_H

# include <stdlib.h>

typedef struct s_chained{
	void				*data;
	struct s_chained	*prev;
	struct s_chained	*next;	
}t_chained;

extern t_chained	*chained_push(void *data);
extern void			chained_next_first(t_chained **head, t_chained *next);
extern void			chained_next_last(t_chained **head, t_chained *next);
extern int			chained_max(t_chained *head);
extern void			chained_pop(t_chained **head);

#endif // CHAINED_H