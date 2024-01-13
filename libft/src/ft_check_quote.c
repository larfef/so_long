/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_quote.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.campus19.be>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 18:43:38 by rkersten          #+#    #+#             */
/*   Updated: 2024/01/06 18:58:24 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	check_quote(char c, char *ptr)
{
	if (c == 39 && *ptr != 34)
	{
		*ptr = 39;
		return (0);
	}
	else if (c == 34 && *ptr != 39)
	{
		*ptr = 34;
		return (0);
	}
	return (0);
}
