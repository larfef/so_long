/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:42:45 by rkersten          #+#    #+#             */
/*   Updated: 2023/05/04 16:10:10 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_u(unsigned int nb, int *ptr)
{
	if (*ptr == -1)
		return ;
	if (nb > 9)
	{
		ft_putnbr(nb / 10, ptr);
		ft_putnbr(nb % 10, ptr);
	}
	if (nb < 10)
		ft_putchar(nb + 48, ptr);
}

void	ft_puthexa(unsigned int nb, int *ptr, char *base)
{
	if (*ptr == -1)
		return ;
	if (nb >= 16)
	{
		put_hexa(nb / 16, ptr, base);
		put_hexa(nb % 16, ptr, base);
	}
	if (nb < 16)
		ft_putchar(base[nb], ptr);
}
