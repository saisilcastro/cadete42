# ifndef ELECTRIC_INSTALATION_H
# define ELECTRIC_INSTALATION_H

# define LIGHTING_POWER_FACTOR 1
# define SOCKET_POWER_FACTOR 0.8

#include <stdio.h>
#include <stdlib.h>

typedef enum e_House{
	LIVING_ROOM,
	BED_ROOM,
	KITCHEN,
	WORKING_ROOM,
	BATH_ROOM,
	HALL,
	VERANDA,
	EXTERNAL,
	MAX_AREA
}t_HOUSE_MENU;

typedef struct s_Wall{
	float	top;
	float	right;
	float	bottom;
	float	left;
}t_WallSet;

typedef struct s_PowerDevice t_PowerDevice;
struct s_PowerDevice{
	char			*name;
	float			power;
	t_PowerDevice	*next;
};

extern t_PowerDevice	*power_device_new(char *name, float power);
extern void				power_next_front(t_PowerDevice **head, t_PowerDevice *next);

typedef struct s_Installation{
	float			aparent_power;
	float			active_power;
	float			area;
	float			perimeter;
	int				socket;
	t_WallSet		wall[1];
	t_HOUSE_MENU	where;
	t_PowerDevice	*devide;
}t_InstalationSet;

extern void		instalation_set(t_InstalationSet *set, float t, float r, float b, float l, int socket, t_HOUSE_MENU where);
extern float	lighting_power_get(t_InstalationSet *set);
extern float	socket_power_get(t_InstalationSet *set);
extern float	active_power_light(t_InstalationSet *set);
extern float	active_power_socket(t_InstalationSet *set);
extern void		show_room_description(t_InstalationSet *set);

typedef struct s_Build{
	t_InstalationSet house[MAX_AREA];
	float	lightin_power;
	float	socket_power;
	float	watt_power;
	float	total_power;
}t_BuiltSet;

extern void build_power_next_front(t_BuiltSet *set, int id, char *name, float power);
extern void	build_make(t_BuiltSet *set);
extern void	build_show_description(t_BuiltSet *set);

#endif // ELECTRIC_INSTALATION