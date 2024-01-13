/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkersten <rkersten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 16:10:54 by rkersten          #+#    #+#             */
/*   Updated: 2023/05/04 16:11:04 by rkersten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
//ft_printf.c
int		ft_printf(const char *f, ...);
int		is_conv(char c);
void	display_f(char *str, char **ptr, int *ret);
void	display_arg(char c, va_list arg, int *ptr);
//display.c
void	ft_putchar(char c, int *ptr);
void	ft_putstr(char *str, int *ptr);
void	ft_putptr(void *ptr, int *ptr_i);
void	put_hexa(size_t nb, int *ptr, char	*base);
void	ft_putnbr(long nb, int *ptr);
//display_2.c
void	ft_putnbr_u(unsigned int nb, int *ptr);
void	ft_puthexa(unsigned int nb, int *ptr, char *base);
int		check_error(const char *f, va_list arg, int i);
#endif