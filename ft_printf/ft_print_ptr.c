/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmachlou <mmachlou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 18:47:28 by mmachlou          #+#    #+#             */
/*   Updated: 2024/06/27 14:20:27 by mmachlou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

int	ft_len_ptr(uintptr_t num)
{
	int	i;

	i = 0;
	while (num != 0)
	{
		i++;
		num /= 16;
	}
	return (i);
}

void	ft_put_ptr(uintptr_t num)
{
	if (num >= 16)
	{
		ft_put_ptr(num / 16);
		ft_put_ptr(num % 16);
	}
	else
	{
		if (num <= 9)
			ft_putchar_fd((num + '0'), 1);
		else
			ft_putchar_fd((num - 10 + 'a'), 1);
	}
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	ptr_len;

	ptr_len = 0;
	if (ptr == 0)
		return (write(1, "(nil)", 5));
	else
	{
		ptr_len += write(1, "0x", 2);
		ft_put_ptr(ptr);
		ptr_len += ft_len_ptr(ptr);
		return (ptr_len);
	}
}
