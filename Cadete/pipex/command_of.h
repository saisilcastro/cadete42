/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_of.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 23:16:10 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/26 22:35:21 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_OF_H
# define COMMAND_OF_H

# include "chained.h"

typedef struct s_command{
	char				*name;
	struct s_chained	*flag;
}t_command;

extern t_command	*command_push(char *name, t_chained *flag);
extern void			command_get(t_command *set, int argc, char **argv);
extern void			command_pop(t_command *set);

#endif // COMMAND_OF_H