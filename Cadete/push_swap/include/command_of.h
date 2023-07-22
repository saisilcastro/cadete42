/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_of.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 01:49:30 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/22 02:50:43 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_OF_H
# define COMMAND_OF_H

# include <stdlib.h>

typedef struct s_command	t_command;
struct s_command{
	char		*data;
	t_command	*next;	
};

extern t_command	*command_push(char *data);
extern int			command_next_first(t_command **head, t_command *set);
extern int			command_next_last(t_command **head, t_command *set);
extern int			command_validate(t_command *head);
extern void			command_pop(t_command **head);

#endif