/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 16:17:00 by ssandman          #+#    #+#             */
/*   Updated: 2020/12/04 16:17:00 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void		print_s(t_flags *flags, va_list args)
{
	char	*str;
	int		len;
	int		spaces;
	int		zeroes;

	if (!(str = va_arg(args, char*)))
		str = "(null)";
	if (flags->precision < (int)ft_strlen(str) && flags->precision > 0)
		len = flags->precision;
	else
		len = (flags->dot && !flags->precision) ? 0 : ft_strlen(str);
	zeroes = flags->width > len && flags->zero ? flags->width - len : 0;
	spaces = flags->width > len && !flags->zero ? flags->width - len : 0;
	flags->printed += len + zeroes + spaces;
	if (flags->minus == 0)
		while (spaces--)
			ft_putchar_fd(' ', 1);
	if (flags->zero == 1)
		while (zeroes-- > 0)
			ft_putchar_fd('0', 1);
	while (len--)
		ft_putchar_fd(*str++, 1);
	if (flags->minus == 1)
		while (spaces--)
			ft_putchar_fd(' ', 1);
}

void		print_c(t_flags *flags, va_list args)
{
	char	symbol;
	int		spaces;

	symbol = va_arg(args, int);
	spaces = flags->width > 1 ? flags->width - 1 : 0;
	flags->printed += 1 + spaces;
	if (flags->minus == 0)
		while (spaces--)
			ft_putchar_fd(' ', 1);
	ft_putchar_fd(symbol, 1);
	if (flags->minus == 1)
		while (spaces--)
			ft_putchar_fd(' ', 1);
}

void		print_prc(t_flags *flags)
{
	int		spaces;
	int		zeroes;
	int		len;

	len = 1;
	zeroes = flags->width > len && flags->zero ? flags->width - len : 0;
	spaces = flags->width > len && !flags->zero ? flags->width - len : 0;
	flags->printed += len + zeroes + spaces;
	if (flags->minus == 0)
		while (spaces--)
			ft_putchar_fd(' ', 1);
	if (flags->zero == 1)
		while (zeroes-- > 0)
			ft_putchar_fd('0', 1);
	while (len--)
		ft_putchar_fd('%', 1);
	if (flags->minus == 1)
		while (spaces--)
			ft_putchar_fd(' ', 1);
}
