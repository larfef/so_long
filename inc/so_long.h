/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:42:27 by rkersten          #+#    #+#             */
/*   Updated: 2023/06/16 17:42:27 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# include "../ft_printf/inc/ft_printf.h"
# include "../libft/inc/libft.h"
# include "mlx.h"

# define BUFFER_SIZE 1
# define HMAX 45
# define IMG 64
# define KEYPRESS 2
# define LMAX 80
# define ONDESTROY 17
# define SIZE 0
# define VALIDE	13
# define X 0
# define Y 1

typedef struct t_struct
{
	char	**map;
	char	path[1];
	int		isize[2];
	size_t	item;
	size_t	mpos[2];
	size_t	ppos[2];
}	t_map;

typedef struct t_struct1
{
	char	**map;
	int		dir[2];
	int		isize[2];
	int		move;
	size_t	item;
	size_t	ipos[2];
	size_t	ppos[2];
	void	*img;
	void	*mlx_p;
	void	*mlx_w;
}	t_hook;

void	exit_err(int errnum);
void	free_table(char **buffer);
void	ft_swap(char *a, char *b);
char	*get_next_line(int fd);
void	init_display(t_hook *data, size_t col, size_t line);
void	init_event(t_hook *data);
int		map_parsing(t_map *data);
void	mdup(char *arg, t_map *data);
void	new_window(t_hook *data);
void	printf_tab(char **tab);

#endif