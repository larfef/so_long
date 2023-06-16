/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:40:50 by rkersten          #+#    #+#             */
/*   Updated: 2023/06/16 17:40:50 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	exit_err(int errnum)
{	
	perror(strerror(errnum));
	exit(EXIT_FAILURE);
}

void	free_table(char **buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i])
		i++;
	while (--i > -1)
		free(buffer[i]);
	free(buffer);
}

void	ft_swap(char *a, char *b)
{
	char	temp;

	temp = *a;
	*a = *b;
	*b = temp;
	if (*a == 'C')
		*a = '0';
}

void	printf_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		ft_printf("%s\n", tab[i]);
		i++;
	}
}
