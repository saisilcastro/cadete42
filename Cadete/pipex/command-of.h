/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command-of.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 23:16:10 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/25 05:54:08 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMAND_OF_H
#define COMMAND_OF_H

#include "chained.h"

typedef struct s_command	t_command;
struct s_command{
	char		*name;
	t_chained	*flag;
};

extern t_command	*command_push(char *name, t_chained *flag);
extern void			command_get(t_command *set, int argc, char **argv);
extern void			command_pop(t_command **set);

#endif // COMMAND_OF_H