#include <stdlib.h>
#include "chained.h"

t_chained	*chained_push(void *data)
{
	t_chained	*set;

	set = (t_chained *)malloc(sizeof(t_chained));
	if (!set)
		return (NULL);
	set->data = data;
	set->prev = NULL;
	set->next = NULL;
	return (set);
}

void	chained_next_first(t_chained **head, t_chained *next)
{
    if (!next)
        return ;
    next->next = *head;
    if (*head)
        (*head)->prev = next;
    *head = next;
}

void	chained_next_last(t_chained **head, t_chained *next)
{
	t_chained *update;

	if (!next)
		return ;
	if (!*head)
	{
		*head = next;
		return ;
	}
	update = *head;
	while (update->next)
		update = update->next;
	next->prev = update;
	update->next = next;
}

void	chained_pop(t_chained **head)
{
	t_chained	*next;

	while (*head)
	{
		next = (*head)->next;
		if ((*head)->data)
			free((*head)->data);
		free(*head);
		*head = next;
	}
}
