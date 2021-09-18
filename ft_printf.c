/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 15:55:00 by ssandman          #+#    #+#             */
/*   Updated: 2020/11/25 15:55:00 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_printf.h"

void			cycle(const char *line, t_flags *flags, va_list args)
{
	flagger(line, flags, args);
	if (line[flags->index] == 'c')
		print_c(flags, args);
	else if (line[flags->index] == 'd' || line[flags->index] == 'i')
		process_di(flags, args);
	else if (line[flags->index] == 's')
		print_s(flags, args);
	else if (line[flags->index] == '%')
		print_prc(flags);
	else if (line[flags->index] == 'x' || line[flags->index] == 'X'
	|| line[flags->index] == 'u')
		process_ux(flags, args, line[flags->index]);
	else if (line[flags->index] == 'p')
		print_ptr(args, flags);
	wipeflags(flags);
}

int				ft_printf(const char *line, ...)
{
	t_flags flags;
	va_list args;

	if (!line)
		return (-1);
	flags.index = 0;
	flags.printed = 0;
	wipeflags(&flags);
	va_start(args, line);
	while (line[flags.index])
	{
		if (line[flags.index] == '%')
			cycle(line, &flags, args);
		else
		{
			ft_putchar_fd(line[flags.index], 1);
			flags.printed++;
		}
		flags.index++;
	}
	va_end(args);
	return (flags.printed);
}
