#include "so_long.h"

int main(int ac, char **av)
{
	t_map	data;
	t_hook	disp;

	if (ac != 2)
		exit(EXIT_FAILURE);
	mdup(av[1], &data);
	map_parsing(&data);
	free_table(data.map);
	mdup(av[1], &data);
	disp.map = data.map;
	disp.ppos[X] = data.ppos[X];
	disp.ppos[Y] = data.ppos[Y];
	disp.item = data.item;
	new_window(&disp);
	init_display(&disp, 0, 0);
	init_event(&disp);
}
