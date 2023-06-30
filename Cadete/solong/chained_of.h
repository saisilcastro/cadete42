/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chained_of.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 08:12:41 by mister-code       #+#    #+#             */
/*   Updated: 2023/06/30 08:52:38 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAINED_OF_H
# define CHAINED_OF_H

# include "system_of.h"

typedef struct s_chained{
	void				*content;
	struct s_chained	*preview;
	struct s_chained	*next;
	t_STATUS			(*next_first)(struct s_chained **head,
		struct s_chained * next);
	t_STATUS			(*next_last)(struct s_chained **head,
		struct s_chained * next);
	void				(*destroy)(void);
}t_chained;

extern t_chained	*chained_new(void *content);
extern t_STATUS		chained_next_first(t_chained **head, t_chained *next);
extern t_STATUS		chained_next_lastt(t_chained **head, t_chained *next);

#endif // CHAINED_OF_H