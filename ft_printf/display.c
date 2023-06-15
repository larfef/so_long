/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 13:08:25 by rkersten          #+#    #+#             */
/*   Updated: 2023/05/04 16:10:14 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c, int *ptr)
{
	if (write(1, &c, 1) == -1)
		*ptr = -1;
	else
		*ptr += 1;
}

void	ft_putstr(char *str, int *ptr)
{
	int	i;

	if (str == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			*ptr = -1;
		else
			*ptr += 6;
		return ;
	}
	i = 0;
	while (str[i])
	{
		if (write(1, &str[i], 1) == -1)
		{
			*ptr = -1;
			return ;
		}
		*ptr += 1;
		i++;
	}
}

void	ft_putptr(void *ptr, int *ptr_i)
{
	size_t	adr;

	adr = (size_t) ptr;
	ft_putstr("0x", ptr_i);
	if (*ptr_i == -1)
		return ;
	put_hexa(adr, ptr_i, "0123456789abcdef");
	if (*ptr_i == -1)
		return ;
}

void	put_hexa(size_t nb, int *ptr, char	*base)
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

void	ft_putnbr(long nb, int *ptr)
{
	if (*ptr == -1)
		return ;
	if (nb < 0)
	{
		ft_putchar('-', ptr);
		nb *= -1;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, ptr);
		ft_putnbr(nb % 10, ptr);
	}
	if (nb >= 0 && nb < 10)
		ft_putchar(nb + 48, ptr);
}
