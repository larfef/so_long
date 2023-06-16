/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 16:48:46 by rkersten          #+#    #+#             */
/*   Updated: 2023/06/16 17:03:08 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static	void	check_arg(int ac, char *str)
{
	if (ac < 2 || str == NULL)
	{
		ft_printf("Erreur\nCarte manquante : ./so_long <map>\n");
		exit(EXIT_FAILURE);
	}
	else if (ac > 2)
	{
		ft_printf("Erreur\nTrop d'arguments : ./so_long <map>\n");
		exit(EXIT_FAILURE);
	}
	while (*str != '.' && *str != '\0')
		str++;
	if (ft_strncmp(".ber", str, 4) != 0 || ft_strlen(str) != 4)
	{
		ft_printf("Erreur\nExtension du fichier carte non valide : <map>.ber");
		exit(EXIT_FAILURE);
	}
	return ;
}

int	main(int ac, char **av)
{
	int		check;
	t_map	data;
	t_hook	disp;

	check_arg(ac, av[1]);
	mdup(av[1], &data);
	check = map_parsing(&data);
	free_table(data.map);
	if (check != VALIDE)
		exit(EXIT_FAILURE);
	mdup(av[1], &data);
	disp.map = data.map;
	disp.ppos[X] = data.ppos[X];
	disp.ppos[Y] = data.ppos[Y];
	disp.item = data.item;
	new_window(&disp);
	init_display(&disp, 0, 0);
	init_event(&disp);
}
