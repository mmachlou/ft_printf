/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmachlou <mmachlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 12:37:35 by mmachlou          #+#    #+#             */
/*   Updated: 2024/06/27 14:23:49 by mmachlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_print_hex(unsigned int num, const char format);
int		ft_print_ptr(unsigned long long ptr);
int		ft_print_unsigned(unsigned int num);
int		ft_printf(const char *fmt, ...);
int		ft_printstr(char *str);
int		ft_printnbr(int num);
int		ft_print_percent(int n);
char	*ft_itoa(int n);
void	ft_putstr(char *str);
void	ft_putchar_fd(char c, int fd);

#endif