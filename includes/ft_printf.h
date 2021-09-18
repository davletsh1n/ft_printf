/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 17:36:00 by ssandman          #+#    #+#             */
/*   Updated: 2020/11/25 17:36:00 by ssandman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_flags
{
	int			index;
	int			printed;
	int			zero;
	int			minus;
	int			width;
	int			dot;
	int			precision;
	int			negative;
}				t_flags;

int				ft_printf(const char *line, ...);
void			wipeflags(t_flags *flags);
void			fprecision(const char *line, t_flags *flags, va_list args);
void			fwidth(const char *line, t_flags *flags, va_list args);
void			fminuszero(const char *line, t_flags *flags);
void			flagger(const char *line, t_flags *flags, va_list args);
void			ft_putnbr_diu(unsigned int n, t_flags *flags);
int				numlen(unsigned long num, int base);
void			process_di(t_flags *flags, va_list args);
void			di_order(t_flags *flags, unsigned int num, int len);
void			print_s(t_flags *flags, va_list args);
void			print_c(t_flags *flags, va_list args);
void			ux_order(t_flags *flags, unsigned int num, int len, char type);
void			process_ux(t_flags *flags, va_list args, char type);
void			print_ptr(va_list args, t_flags *flags);
void			put_hex(unsigned long n, char type);
void			print_ptr(va_list args, t_flags *flags);
void			printhex(char *hex, char type, int index);
void			put0x(t_flags *flags);
void			calc_ptr(t_flags *flags, va_list args, char type);
int				ft_isdigit(int c);
void			ft_putchar_fd(char c, int fd);
void			ft_putnbr_fd(long long int n, int fd);
size_t			ft_strlen(const char *str);
int				ft_tolower(int c);
void			print_prc(t_flags *flags);
#endif
