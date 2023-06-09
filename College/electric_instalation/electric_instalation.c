#include "electric_instalation.h"
#include <math.h>

t_PowerDevice *power_device_new(char *name, float power)
{
	t_PowerDevice *set = (t_PowerDevice *)malloc(sizeof(t_PowerDevice));
	set->name = name;
	set->power = power;
	set->next = NULL;
	return (set);
}

void	power_next_front(t_PowerDevice **head, t_PowerDevice *next)
{
	if (!next)
		return ;
	if (!*head)
	{
		*head = next;
		return ;
	}
	next->next = *head;
	*head = next;
}

static char	*where_name_get(t_InstalationSet *set);

void	instalation_set(t_InstalationSet *set, float t, float r, float b, float l, int socket, t_HOUSE_MENU where)
{
	if (!set)
		return ;
	set->aparent_power = 0;
	set->active_power = 0;
	set->wall->top = t;
	set->wall->right = r;
	set->wall->bottom = b;
	set->wall->left = l;
	set->where = where;
	set->perimeter = t + r + b + l + ((set->where == KITCHEN) ? 1 : 0);
	set->socket = socket;
	set->area = (set->wall->top * set->wall->right) + ((set->where == KITCHEN) ? 1 : 0);
	set->devide = NULL;
}

float	lighting_power_get(t_InstalationSet *set)
{
	float	space;
	int		whole_va;

	if (!set)
		return 0.0;
	if (set->where != KITCHEN)
		space = set->area - 6;
	else
		space = (set->area + 1) - 6;
	whole_va = (((int)space - (int)space % 4) / 4);
	set->aparent_power += 100 + ((whole_va > 0) ? (whole_va * 60) : 0);
	return (set->aparent_power);
}

float	socket_power_get(t_InstalationSet *set)
{
	if (!set)
		return (0.0);
	if (set->area < 6)
	{
		if (set->where != LIVING_ROOM && set->where != BED_ROOM)
		{
			if (set->socket < 4)
				set->socket = 4;
			set->active_power = set->socket * 100.0;
		}
		else
		{
			if (set->socket < 1)
				set->socket = 1;
			set->active_power = set->socket * 100.0;
		}
	}
	else
	{
		if (set->where == LIVING_ROOM || set->where == BED_ROOM)
		{
			float divisor = (set->perimeter / 5);
			float rest = (float)ceil((divisor - (int)divisor));
			int   socket = (int)(divisor + rest);
			if (set->socket < socket)
				set->socket = socket;	
			set->active_power = socket * 100.0;
		}
		else if (set->where == KITCHEN || set->where == WORKING_ROOM)
		{
			float divisor = (set->perimeter / 3.5);
			float rest = (float)ceil((divisor - (int)divisor));
			int socket = (int)ceil(divisor + rest);
			int socket_remain;
			if (set->socket < socket)
				set->socket = socket;
			socket_remain = set->socket - 3;
			socket = set->socket - socket_remain;
			set->active_power += socket * 600.0;
			set->active_power += socket_remain * 100.0;
		}
		else
		{
			if (set->socket < 1)
				set->socket = 1;
			set->active_power = 100.0 * set->socket;
		}
	}
	return (set->active_power);
}

void	socket_va_get(t_InstalationSet *set)
{
	if (!set)
		return ;
	
}

void		show_room_description(t_InstalationSet *set)
{
	printf("Parametros de %s\n"
		   "Area: %.2f m^2\n"
		   "Perimetro: %.2f m\n"
		   "Potencia de iluminacao: %.f\n"
		   "Potencia de tomada: %.f\n"
		   "VA tomadas: %i\n\n"
		   , where_name_get(set), set->area, set->perimeter,
		   set->aparent_power, set->active_power, set->socket);
}

static char	*where_name_get(t_InstalationSet *set)
{
	char	*room = "";

	if (!set)
		return room;
	switch (set->where)
	{
		case LIVING_ROOM:room = "sala";break;
		case BED_ROOM:room = "quarto";break;
		case KITCHEN:room = "cozinha";break;
		case WORKING_ROOM:room = "area de servicos";break;
		case BATH_ROOM: room = "banheiro";break;
		case HALL: room = "corredor"; break;
		case VERANDA: room = "varanda"; break;
		case EXTERNAL: room = "area externa"; break;
		case MAX_AREA:break;
	}
	return room;
}

void build_power_next_front(t_BuiltSet *set, int id, char *name, float power)
{
	power_next_front(&set->house[id].devide, power_device_new(name, power));
}

void	build_make(t_BuiltSet *set)
{
	int				i;
	t_PowerDevice	*device;

	i = 0;
	while (i < MAX_AREA)
	{
		set->lightin_power += lighting_power_get(&set->house[i]);
		set->socket_power += socket_power_get(&set->house[i]);
		device = set->house[i].devide;
		while (device)
		{
			set->watt_power += device->power;
			device = device->next;
		}
		i++;
	}
}

void	build_show_description(t_BuiltSet *set)
{
	int	i;

	if (!set)
		return ;
	i = 0;
	while(i < MAX_AREA)
	{
		show_room_description(&set->house[i]);
		i++;
	}
	set->total_power = (set->lightin_power * LIGHTING_POWER_FACTOR) + (set->socket_power * SOCKET_POWER_FACTOR) + set->watt_power;
	printf("Potencia de iluminacao total: %.2f(VA)\n", set->lightin_power);
	printf("Potencia de tomada total: %.2f(VA)\n", set->socket_power);
	printf("Potencia de dispositivos %.2f(W)\n", set->watt_power);
	printf("Potencia total %.2f(W)\n", set->total_power);
}
