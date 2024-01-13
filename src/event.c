/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:28:43 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/13 13:15:32 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/so_long.h"

static int	close_win(t_hook *data)
{
	mlx_clear_window(data->mlx_p, data->mlx_w);
	free_table(data->map);
	exit(EXIT_SUCCESS);
	return (1);
}

static void	display_move(t_hook *data)
{
	data->img = mlx_xpm_file_to_image(data->mlx_p, "./textures/Background.xpm",
			&data->isize[X], &data->isize[Y]);
	mlx_put_image_to_window(data->mlx_p, data->mlx_w,
		data->img, data->ppos[X] * IMG, data->ppos[Y] * IMG);
	data->img = mlx_xpm_file_to_image(data->mlx_p, "./textures/Player.xpm",
			&data->isize[X], &data->isize[Y]);
	mlx_put_image_to_window(data->mlx_p, data->mlx_w,
		data->img, (data->ppos[X] + data->dir[X]) * IMG,
		(data->ppos[Y] + data->dir[Y]) * IMG);
	data->ppos[X] += data->dir[X];
	data->ppos[Y] += data->dir[Y];
	data->move++;
	ft_printf("Mouvements : %i\n", data->move);
}

static void	p_move(t_hook *data)
{
	char	*pos;
	char	*move;

	pos = &data->map[data->ppos[Y]][data->ppos[X]];
	move = &data->map[data->ppos[Y] + data->dir[Y]]
	[data->ppos[X] + data->dir[X]];
	if (*move == 'C' || *move == '0')
	{
		if (*move == 'C')
			data->item--;
		ft_swap(pos, move);
		display_move(data);
	}
	else if (*move == 'E' && !data->item)
	{
		mlx_clear_window(data->mlx_p, data->mlx_w);
		free_table(data->map);
		exit(EXIT_SUCCESS);
	}
}

static int	k_input(int key, t_hook *data)
{
	if (key == 53)
	{
		mlx_clear_window(data->mlx_p, data->mlx_w);
		free_table(data->map);
		exit(EXIT_SUCCESS);
	}
	if (key == 126 || key == 125 || key == 123 || key == 124)
	{
		if (key == 126 || key == 125)
		{
			data->dir[X] = 0;
			data->dir[Y] = 1;
			if (key == 126)
				data->dir[Y] = -1;
		}
		else if (key == 123 || key == 124)
		{
			data->dir[X] = 1;
			data->dir[Y] = 0;
			if (key == 123)
				data->dir[X] = -1;
		}
		p_move(data);
	}
	return (0);
}

void	init_event(t_hook *data)
{
	data->move = 0;
	mlx_hook(data->mlx_w, KEYPRESS, 0, &k_input, data);
	mlx_hook(data->mlx_w, ONDESTROY, 0, &close_win, data);
	mlx_loop(data->mlx_p);
}
