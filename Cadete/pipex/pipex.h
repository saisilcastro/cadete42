/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 10:59:15 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/18 18:20:26 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

typedef struct s_chained	t_chained;
struct s_chained{
	void		*data;
	t_chained	*prev;
	t_chained	*next;	
};

extern t_chained	*chained_set(void *data);
extern void			chained_next_last(t_chained **head, t_chained *next);
extern void			chained_delete(t_chained **head);

typedef struct s_pipex		t_pipex;
struct s_pipex{
	char		*input;
	char		*output;
	t_chained	*cmd;
};

extern void			pipex_start(t_pipex *set);

#endif // PIPEX_H