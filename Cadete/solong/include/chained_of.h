/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_of.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 08:12:41 by mister-code       #+#    #+#             */
/*   Updated: 2023/06/30 15:37:37 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAINED_OF_H
# define CHAINED_OF_H

# include "system_of.h"

typedef struct s_chained	t_chained;
struct s_chained{
	void		*data;
	t_chained	*prev;
	t_chained	*next;
	void		(*next_first)(t_chained **head, t_chained *next);
	void		(*next_last)(t_chained **head, t_chained *next);
	void		(*destroy)(t_chained *head, void (*del)(void *data));
};

extern t_chained		*chained_new(void *content);
extern void				chained_next_first(t_chained **head, t_chained *next);
extern void				chained_next_lastt(t_chained **head, t_chained *next);

#endif // CHAINED_OF_H