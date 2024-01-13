/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:26:45 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/13 13:01:23 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

void	new_window(t_hook *data)
{
	size_t	size;

	size = 0;
	while (data->map[size])
		size++;
	data->ipos[X] = 0;
	data->ipos[Y] = 0;
	data->mlx_p = mlx_init();
	data->mlx_w = mlx_new_window(data->mlx_p,
			ft_strlen(data->map[0]) * IMG, size * IMG, "So_long");
}

static void	display_img(t_hook *data, char *path)
{
	data->img = mlx_xpm_file_to_image(data->mlx_p, path,
			&data->isize[X], &data->isize[Y]);
	mlx_put_image_to_window(data->mlx_p, data->mlx_w, data->img,
		data->ipos[X], data->ipos[Y]);
}

static void	load_img(t_hook *data, size_t col, size_t line)
{
	char	*path;

	path = NULL;
	if (data->map[col][line] == '1')
		path = "./textures/Wall.xpm";
	else if (data->map[col][line] == '0' || data->map[col][line] == 'P'
		|| data->map[col][line] == 'C')
		path = "./textures/Background.xpm";
	else if (data->map[col][line] == 'E')
		path = "./textures/Exit.xpm";
	display_img(data, path);
	if (data->map[col][line] == 'C')
		path = "./textures/Collectible.xpm";
	else if (data->map[col][line] == 'P')
		path = "./textures/Player.xpm";
	if (data->map[col][line] == 'P' || data->map[col][line] == 'C')
		display_img(data, path);
}

void	init_display(t_hook *data, size_t col, size_t line)
{
	if (!data->map[col])
		return ;
	load_img(data, col, line);
	data->ipos[X] += IMG;
	if (data->map[col][line + 1])
		init_display(data, col, line + 1);
	else
	{
		data->ipos[X] = 0;
		data->ipos[Y] += IMG;
		init_display(data, col + 1, 0);
	}
}
