/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_diu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 11:37:00 by ssandman          #+#    #+#             */
/*   Updated: 2020/12/12 17:14:55 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void	ft_putnbr_diu(unsigned int n, t_flags *flags)
{
	if (n >= 10)
	{
		ft_putnbr_diu((n / 10), flags);
	}
	ft_putchar_fd(n % 10 + '0', 1);
}

int		numlen(unsigned long num, int base)
{
	int		len;

	len = 1;
	while (num >= (unsigned long)base)
	{
		len++;
		num /= base;
	}
	return (len);
}

void	di_order(t_flags *flags, unsigned int num, int len)
{
	int		zeroes;
	int		spaces;

	if (flags->negative == 1)
		len++;
	if (flags->dot && !flags->precision && !num)
		len = 0;
	if (flags->precision > len)
		zeroes = flags->precision - len;
	else
		zeroes = (flags->width > len && flags->zero) ? flags->width - len : 0;
	len += zeroes > 0 ? zeroes : 0;
	spaces = flags->width > len && !flags->zero ? flags->width - len : 0;
	flags->printed += len + spaces;
	if (!flags->minus)
		while (spaces-- > 0)
			ft_putchar_fd(' ', 1);
	flags->negative ? ft_putchar_fd('-', 1) : 0;
	while (zeroes-- > 0)
		ft_putchar_fd('0', 1);
	if (len)
		ft_putnbr_diu(num, flags);
	if (flags->minus)
		while (spaces-- > 0)
			ft_putchar_fd(' ', 1);
}

void	process_di(t_flags *flags, va_list args)
{
	long	num;
	int		len;

	num = va_arg(args, int);
	if (num < 0)
	{
		flags->negative = 1;
		num = num * -1;
		if (flags->precision > 0)
			flags->precision++;
	}
	len = numlen(num, 10);
	di_order(flags, num, len);
}
