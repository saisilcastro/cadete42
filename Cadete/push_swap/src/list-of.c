/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list-of.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 01:41:57 by mister-code       #+#    #+#             */
/*   Updated: 2023/07/23 03:19:28 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <list_of.h>
#include <stdlib.h>
#include <ft_printf.h>

void	list_set(t_list *list)
{
	list->a = NULL;
	list->b = NULL;
	list->a_max = 0;
	list->b_max = 0;
}

void	list_sort(t_list *list)
{
	int	i;

	if (!list)
		return ;
	i = 0;
	while (i < list->a_max)
	{
		i++;
	}
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
