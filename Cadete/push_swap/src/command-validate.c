/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command-validate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mister-coder <mister-coder@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 02:45:40 by lde-cast          #+#    #+#             */
/*   Updated: 2023/07/23 13:48:18 by mister-code      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <command_of.h>
#include <ft_atoi_base.h>
#include <ft_printf.h>

static int	list_copy(t_list *list, t_command *head)
{
	t_command	*update;
	int			i;

	update = head;
	i = 0;
	while (update)
	{
		*(list->a + i) = ft_atoi_base(update->data, 10);
		if (*(list->a + i) > (int)0x7FFFFFFF)
			return (0);
		update = update->next;
		i++;
	}
	return (1);
}

static int	list_push(t_list *list, t_command *head)
{
	list->a = (int *)malloc((list->a_max + 1) * sizeof(int));
	if (!list->a)
		return (0);
	list->b = (int *)malloc((list->a_max + 1) * sizeof(int));
	if (!list->b)
		return (0);
	return (list_copy(list, head));
}

static int	list_repeat(t_list *list)
{
	int	i;
	int	j;

	if (!list->a)
		return (1);
	i = -1;
	while (++i < list->a_max)
	{
		j = i;
		while (++j < list->a_max)
		{
			if (*(list->a + i) == *(list->a + j))
				return (1);
		}
	}
	return (0);
}

int	command_validate(t_command *head, t_list *list)
{
	t_command	*update;
	char		*buffer;

	if (!head)
		return (0);
	update = head;
	while (update)
	{
		buffer = update->data;
		while (buffer && *buffer && (*buffer == '-' 
				|| (*buffer >= '0' && *buffer <= '9')))
			buffer++;
		if (buffer && *buffer)
			return (0);
		update = update->next;
		list->a_max++;
	}
	if (!list_push(list, head) || list_repeat(list))
		return (0);
	command_pop(&head);
	return (1);
}
