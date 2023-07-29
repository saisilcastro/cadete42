/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list-of.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lde-cast <lde-cast@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 01:41:57 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/24 20:34:48 by lde-cast         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list_of.h>
#include <stdlib.h>
#include <ft_printf.h>
#include <rotate_of.h>

void	list_set(t_list *list)
{
	list->a = NULL;
	list->b = NULL;
	list->a_max = 0;
	list->b_max = 0;
}

void	list_sort(t_list *list)
{
	if (!list)
		return ;
	reverse_rotate_int(list->a, list->a_max);
}

void	list_pop(t_list *list)
{
	if (!list)
		return ;
	if (list->a)
		free(list->a);
	if (list->b)
		free(list->b);
}
