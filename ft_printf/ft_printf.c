/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 12:23:41 by rkersten          #+#    #+#             */
/*   Updated: 2023/05/04 16:10:35 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *f, ...)
{
	char	*ptr;
	va_list	arg;
	int		ret;

	va_start(arg, f);
	ret = 0;
	ptr = (char *) f;
	while (ptr)
	{
		display_f(ptr, &ptr, &ret);
		if (ret == -1)
			return (-1);
		if (*ptr && is_conv(*(++ptr)))
			display_arg(*ptr, arg, &ret);
		else if (*ptr)
			ft_putchar(*ptr, &ret);
		if (ret == -1)
			return (-1);
		if (!*ptr)
			break ;
		ptr++;
	}
	va_end(arg);
	return (ret);
}

void	display_arg(char c, va_list arg, int *ptr)
{
	if (c == 'c')
		ft_putchar(va_arg(arg, int), ptr);
	if (c == 's')
		ft_putstr(va_arg(arg, char *), ptr);
	if (c == 'p')
		ft_putptr(va_arg(arg, void *), ptr);
	if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(arg, int), ptr);
	if (c == 'u')
		ft_putnbr_u(va_arg(arg, int), ptr);
	if (c == 'x')
		ft_puthexa(va_arg(arg, int), ptr, "0123456789abcdef");
	if (c == 'X')
		ft_puthexa(va_arg(arg, int), ptr, "0123456789ABCDEF");
}

int	is_conv(char c)
{
	char	*conv;

	conv = "cspdiuxX";
	while (*conv)
	{
		if (c == *conv)
			return (1);
		conv++;
	}
	return (0);
}

void	display_f(char *str, char **ptr, int *ret)
{
	if (*ret == -1)
		return ;
	if (*str && *str != '%')
	{
		*ptr += 1;
		ft_putchar(*str, ret);
		display_f(str + 1, ptr, ret);
	}
	else if (*str == '%' && *(str + 1) == '%')
	{
		*ptr += 2;
		ft_putchar(*str, ret);
		display_f(str + 2, ptr, ret);
	}
}
