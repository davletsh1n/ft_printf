/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 14:12:00 by ssandman          #+#    #+#             */
/*   Updated: 2020/12/01 14:12:00 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void	wipeflags(t_flags *flags)
{
	flags->zero = 0;
	flags->width = 0;
	flags->minus = 0;
	flags->dot = 0;
	flags->precision = 0;
	flags->negative = 0;
}

void	fprecision(const char *line, t_flags *flags, va_list args)
{
	flags->dot = 1;
	flags->index++;
	if (line[flags->index] == '*')
	{
		flags->precision = va_arg(args, int);
		flags->zero = flags->precision >= 0 ? 0 : flags->zero;
		flags->index++;
	}
	else
		while (ft_isdigit(line[flags->index]))
		{
			flags->precision = flags->precision * 10 + line[flags->index] - '0';
			flags->index++;
			flags->zero = 0;
		}
}

void	fwidth(const char *line, t_flags *flags, va_list args)
{
	if (line[flags->index] == '*')
	{
		flags->width = va_arg(args, int);
		flags->index++;
		if (flags->width < 0)
		{
			flags->zero = 0;
			flags->minus = 1;
			flags->width *= -1;
		}
	}
	else
	{
		while (ft_isdigit(line[flags->index]))
		{
			flags->width = flags->width * 10 + line[flags->index] - '0';
			flags->index++;
		}
	}
}

void	fminuszero(const char *line, t_flags *flags)
{
	while (line[flags->index] == '-' || line[flags->index] == '0')
	{
		if (line[flags->index] == '-')
			flags->minus = 1;
		else if (line[flags->index] == '0' && !flags->minus)
			flags->zero = 1;
		flags->index++;
	}
	if (flags->minus == 1 && flags->zero == 1)
		flags->zero = 0;
}

void	flagger(const char *line, t_flags *flags, va_list args)
{
	flags->index++;
	if (line[flags->index] == '-' || line[flags->index] == '0')
		fminuszero(line, flags);
	fwidth(line, flags, args);
	if (line[flags->index] == '.')
		fprecision(line, flags, args);
}
