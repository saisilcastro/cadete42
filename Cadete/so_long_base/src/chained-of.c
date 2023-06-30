#include <chained-of.h>
#include <stdlib.h>

static void chained_function(t_chained *set);

t_chained	*chained_new(void *content)
{
	t_chained   *set = (t_chained *)malloc(sizeof(t_chained));
	if (!set)
		return (NULL);
	set->content = content;
	set->preview = NULL;
	set->next = NULL;
	chained_function(set);
	return (set);
}

STATUS    chained_next_first(t_chained **head, t_chained *next)
{
    if (!next)
        return (Off);
    next->next = *head;
    if (*head)
        (*head)->preview = next;
    *head = next;
    return (On);
}

static STATUS	chained_next_last(t_chained **head, t_chained *next)
{
	t_chained *update;

	if (!next)
		return (Off);
	if (!*head)
	{
		*head = next;
		return (On);
	}
	update = *head;
	while (update->next)
		update = update->next;
	next->preview = update;
	update->next = next;
	return (On);
}

static void	chained_destroy(t_chained *set)
{
	t_chained   *next;

	while (set)
	{
		next = set->next;
		free(set);
		set = NULL;
		set = next;
	}
}

static void	chained_function(t_chained *set)
{
	if (!set)
		return ;
	set->next_first = chained_next_first;
	set->next_last = chained_next_last;
	set->destroy = chained_destroy;
}