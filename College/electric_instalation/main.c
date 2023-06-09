#include "electric_instalation.h"

void	setting(t_BuiltSet *set);

int	main(void)
{
	t_BuiltSet	build;

	setting(&build);
	build_make(&build);
	build_show_description(&build);
	return (0);
}

void	setting(t_BuiltSet *set)
{
	if (!set)
		return ;
	
	set->lightin_power = 0;
	set->socket_power = 0;
	set->watt_power = 0;
	set->total_power = 0;
	instalation_set(&set->house[LIVING_ROOM], 4.65, 3, 4.65, 3, 1, LIVING_ROOM);
	instalation_set(&set->house[BED_ROOM], 3, 3, 3, 3, 1, BED_ROOM);
	instalation_set(&set->house[KITCHEN], 1.5, 4, 2.5, 1, 1, KITCHEN);
	build_power_next_front(set, KITCHEN, "Torneira eletrica", 5000);
	instalation_set(&set->house[WORKING_ROOM], 2.5, 2, 2.5, 2 , 1, WORKING_ROOM);
	build_power_next_front(set, WORKING_ROOM, "Maquina de lavar", 1000);
	instalation_set(&set->house[BATH_ROOM], 2, 1.85, 2 , 1.85, 1, BATH_ROOM);
	build_power_next_front(set, WORKING_ROOM, "Chuveiro", 6800);
	instalation_set(&set->house[HALL], 2, 1, 2 , 1, 1, HALL);
	instalation_set(&set->house[VERANDA], 3, 1.35, 3, 1.35, 1, VERANDA);
	instalation_set(&set->house[EXTERNAL], 7.5, 7.2, 7.5, 7.2, 1, EXTERNAL);
}
