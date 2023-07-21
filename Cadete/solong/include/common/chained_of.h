/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_of.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 08:12:41 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/20 23:58:46 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAINED_OF_H
# define CHAINED_OF_H

# include <stdlib.h>
# include <system_of.h>

typedef struct s_chained	t_chained;
struct s_chained{
	void		*data;
	t_chained	*prev;
	t_chained	*next;
	void		(*next_first)(t_chained **head, t_chained *next);
	void		(*next_last)(t_chained **head, t_chained *next);
	void		(*destroy)(t_chained *head, void (*del)(void *data));
};

extern t_chained		*chained_push(void *content);
extern void				chained_next_first(t_chained **head, t_chained *next);
extern void				chained_next_last(t_chained **head, t_chained *next);

#endif // CHAINED_OF_H