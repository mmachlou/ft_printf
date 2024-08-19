/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmachlou <mmachlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:23:31 by mmachlou          #+#    #+#             */
/*   Updated: 2024/06/27 12:58:47 by mmachlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h" 

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_fmt(const char fmt, va_list args)
{
	int	i;

	i = 0;
	if (fmt == 'c')
		i += ft_printchar(va_arg(args, int));
	else if (fmt == 's')
		i += ft_printstr(va_arg(args, char *));
	else if (fmt == 'p')
		i += ft_print_ptr(va_arg(args, unsigned long long));
	else if (fmt == 'd' || fmt == 'i')
		i += ft_printnbr(va_arg(args, int));
	else if (fmt == 'u')
		i += ft_print_unsigned(va_arg(args, unsigned int));
	else if (fmt == 'x' || fmt == 'X')
		i += ft_print_hex(va_arg(args, unsigned int), fmt);
	else if (fmt == '%')
		i += write(1, "%", 1);
	return (i);
}

int	ft_printf(const char *fmt, ...)
{
	va_list			args;
	int				print_len;

	print_len = 0;
	va_start(args, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			print_len += ft_fmt(*(fmt + 1), args);
			fmt++;
		}
		else
		{
			print_len += ft_printchar(*fmt);
		}
		fmt++;
	}
	va_end(args);
	return (print_len);
}
