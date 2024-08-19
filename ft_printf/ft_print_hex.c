/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmachlou <mmachlou@student.42.fr>          +#+  +:+        +#+		  */
/*                                                +#+#+#+#+#+     +#+         */
/*   Created: 2024/06/24 16:45:11 by mmachlou           #+#     #+#           */
/*   Updated: 2024/06/24 16:46:39 by mmachlou           ###   ########.fr     */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_hex(unsigned int num)
{
	int	i;

	i = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		num /= 16;
		i++;
	}
	return (i);
}

void	ft_put_hex(unsigned int num, const char format)
{
	if (num >= 16)
	{
		ft_put_hex(num / 16, format);
		ft_put_hex(num % 16, format);
	}
	else
	{
		if (num < 10)
			ft_putchar_fd((num + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((num - 10) + 'a', 1);
			if (format == 'X')
				ft_putchar_fd((num - 10) + 'A', 1);
		}
	}
}

int	ft_print_hex(unsigned int num, const char format)
{
	if (num == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	else
	{
		ft_put_hex(num, format);
		return (ft_len_hex(num));
	}
}
