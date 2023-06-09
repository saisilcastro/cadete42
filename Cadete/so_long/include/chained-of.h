#ifndef CHAINED_OF_H
#define CHAINED_OF_H

#include <system-of.h>

typedef struct s_chained t_chained;
struct s_chained{
	void		*content;
	t_chained	*preview;
	t_chained	*next;
	STATUS		(*next_first)(t_chained **head, t_chained *next);
	STATUS		(*next_last)(t_chained **head, t_chained *next);
	void		(*destroy)();
};

extern t_chained    *chained_new(void *content);
extern STATUS		chained_next_first(t_chained **head, t_chained *next);
extern STATUS		chained_next_lastt(t_chained **head, t_chained *next);

#endif // CHAINED_OF_H