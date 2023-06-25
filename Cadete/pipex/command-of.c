/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command-of.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 23:20:06 by lde-cast          #+#    #+#             */
/*   Updated: 2023/06/25 05:56:56 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "command-of.h"

t_command	*command_push(char *name, t_chained *flag)
{
	t_command	*set = (t_command *)malloc(sizeof(t_command));
	set->name = name;
	set->flag = flag;
	return (set);
}

void	command_pop(t_command **set)
{
	t_chained	*next;

	if (!*set)
		return ;
	if ((*set)->name)
		free((*set)->name);
	while ((*set)->flag)
	{
		next = (*set)->flag;
		if ((*set)->flag->data)
			free((*set)->flag->data);
		free((*set)->flag);
		(*set)->flag = next;
	}
}