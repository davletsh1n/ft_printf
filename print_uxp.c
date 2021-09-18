/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 11:20:00 by ssandman          #+#    #+#             */
/*   Updated: 2020/12/06 11:20:00 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void		printhex(char *hex, char type, int index)
{
	if (type == 'X')
		while (index >= 0)
		{
			ft_putchar_fd(hex[index], 1);
			index--;
		}
	else if (type == 'x')
		while (index >= 0)
		{
			ft_putchar_fd((char)ft_tolower(hex[index]), 1);
			index--;
		}
	else if (type == 'p')
	{
		while (index >= 0)
		{
			ft_putchar_fd((char)ft_tolower(hex[index]), 1);
			index--;
		}
	}
}

void		put_hex(unsigned long n, char type)
{
	char				hex[100];
	unsigned long		reminder;
	int					index;

	index = 0;
	if (n == 0)
		ft_printf("%d", 0);
	while (n > 0)
	{
		reminder = n % 16;
		if (reminder < 10)
			hex[index] = reminder + 48;
		else
			hex[index] = reminder + 55;
		index++;
		n /= 16;
	}
	index = index - 1;
	printhex(hex, type, index);
}

void		ux_order(t_flags *flags, unsigned int num, int len, char type)
{
	int					zeroes;
	int					spaces;

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
		type == 'u' ? ft_putnbr_diu(num, flags) : put_hex(num, type);
	if (flags->minus)
		while (spaces-- > 0)
			ft_putchar_fd(' ', 1);
}

void		process_ux(t_flags *flags, va_list args, char type)
{
	unsigned int		num;
	int					len;

	num = va_arg(args, unsigned int);
	len = type == 'u' ? numlen(num, 10) : numlen(num, 16);
	ux_order(flags, num, len, type);
}

void		print_ptr(va_list args, t_flags *flags)
{
	unsigned long int	ptr;
	int					len;
	int					spaces;
	int					precision;

	ptr = va_arg(args, unsigned long int);
	len = numlen(ptr, 16);
	precision = flags->precision > len ? flags->precision - len : 0;
	len = !ptr && flags->dot && !flags->precision ? 2 : len + 2;
	spaces = flags->width > len ? flags->width - len : 0;
	flags->printed += len + spaces + precision;
	if (!flags->minus)
		while (spaces--)
			ft_putchar_fd(' ', 1);
	write(1, "0x", 2);
	while (precision--)
		ft_putchar_fd('0', 1);
	if (len > 2)
		put_hex(ptr, 'p');
	if (flags->minus)
		while (spaces-- > 0)
			ft_putchar_fd(' ', 1);
}
